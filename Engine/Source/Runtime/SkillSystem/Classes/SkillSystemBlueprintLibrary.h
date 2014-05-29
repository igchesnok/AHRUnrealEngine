// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Abilities/GameplayAbility.h"
#include "SkillSystemBlueprintLibrary.generated.h"

class UBlueprintPlayMontageAndWaitTaskProxy;

UCLASS(MinimalAPI)
class USkillSystemBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "Utilities|FlowControl", meta = (Latent, HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", LatentInfo = "LatentInfo" ))
	static void	StaticFuncPlayMontageAndWait(AActor* WorldContextObject, UAnimMontage * Montage, struct FLatentActionInfo LatentInfo);


	UFUNCTION(BlueprintCallable, meta=(HidePin="WorldContextObject", DefaultToSelf="WorldContextObject", BlueprintInternalUseOnly = "TRUE"))
	static class UAbilityTask_PlayMontageAndWait* CreatePlayMontageAndWaitProxy(class UObject* WorldContextObject, class UAnimMontage *MontageToPlay);

	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", BlueprintInternalUseOnly = "TRUE"))
	static class UAbilityTask_WaitMovementModeChange* CreateWaitMovementModeChange(class UObject* WorldContextObject, EMovementMode NewMode);
};