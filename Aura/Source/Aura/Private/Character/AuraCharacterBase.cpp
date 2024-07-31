// Copyright Knightfall Interactive


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraCharacterBase::InitAbilitySystemInfo()
{
}
