// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

/** 
 * Playable sound object for spoken dialogue 
 */

#include "DialogueTypes.h"

#include "DialogueVoice.generated.h"

UCLASS(hidecategories=Object, editinlinenew, MinimalAPI, BlueprintType)
class UDialogueVoice : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category=DialogueVoice, AssetRegistrySearchable)
	TEnumAsByte<EGrammaticalGender::Type> Gender;

	UPROPERTY(EditAnywhere, Category=DialogueVoice, AssetRegistrySearchable)
	TEnumAsByte<EGrammaticalNumber::Type> Plurality;

	UPROPERTY()
	FGuid LocalizationGUID;

public:
	// Begin UObject interface. 
	virtual bool IsReadyForFinishDestroy() override;
	virtual FName GetExporterName() override;
	virtual FString GetDesc() override;
	virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override;

	virtual void PostDuplicate(bool bDuplicateForPIE);
	// End UObject interface. 
};