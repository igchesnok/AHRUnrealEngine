
#include "AbilitySystemPrivatePCH.h"
#include "Abilities/Tasks/AbilityTask_WaitAbilityCommit.h"

#include "AbilitySystemComponent.h"

#include "Abilities/GameplayAbility.h"


UAbilityTask_WaitAbilityCommit::UAbilityTask_WaitAbilityCommit(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

UAbilityTask_WaitAbilityCommit* UAbilityTask_WaitAbilityCommit::WaitForAbilityCommit(UObject* WorldContextObject, FGameplayTag InWithTag, FGameplayTag InWithoutTag)
{
	auto MyObj = NewTask<UAbilityTask_WaitAbilityCommit>(WorldContextObject);
	MyObj->WithTag = InWithTag;
	MyObj->WithoutTag = InWithoutTag;

	return MyObj;
}

void UAbilityTask_WaitAbilityCommit::Activate()
{
	if (AbilitySystemComponent.IsValid())	
	{		
		AbilitySystemComponent->AbilityCommitedCallbacks.AddUObject(this, &UAbilityTask_WaitAbilityCommit::OnAbilityCommit);
	}
}

void UAbilityTask_WaitAbilityCommit::OnDestroy(bool AbilityEnded)
{
	if (AbilitySystemComponent.IsValid())
	{
		AbilitySystemComponent->AbilityCommitedCallbacks.RemoveUObject(this, &UAbilityTask_WaitAbilityCommit::OnAbilityCommit);
	}

	Super::OnDestroy(AbilityEnded);
}

void UAbilityTask_WaitAbilityCommit::OnAbilityCommit(UGameplayAbility *ActivatedAbility)
{
	if ( (WithTag.IsValid() && !ActivatedAbility->AbilityTags.HasTag(WithTag, EGameplayTagMatchType::IncludeParentTags, EGameplayTagMatchType::Explicit)) ||
		 (WithoutTag.IsValid() && ActivatedAbility->AbilityTags.HasTag(WithoutTag, EGameplayTagMatchType::IncludeParentTags, EGameplayTagMatchType::Explicit)))
	{
		// Failed tag check
		return;
	}

	OnCommit.Broadcast(ActivatedAbility);

	EndTask();
}