// Copyright Knightfall Interactive


#include "AbilitySystem/ModMageCalc/MMC_MaxMana.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	InterlligenceDef.AttributeToCapture =UAuraAttributeSet::GetIntelligenceAttribute();
	InterlligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	InterlligenceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(InterlligenceDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluatedParameters;
	EvaluatedParameters.SourceTags = SourceTags;
	EvaluatedParameters.TargetTags = TargetTags;

	float Interlligence = 0.f;
	GetCapturedAttributeMagnitude(InterlligenceDef, Spec, EvaluatedParameters, Interlligence);
	Interlligence = FMath::Max<float>(Interlligence, 0.f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	return 50.f + 2.5f * Interlligence + 15.f * PlayerLevel;
}
