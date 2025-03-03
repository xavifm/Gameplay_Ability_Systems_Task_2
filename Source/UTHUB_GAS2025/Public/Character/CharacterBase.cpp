#include "./CharacterBase.h"
#include "Kismet/GameplayStatics.h"

ACharacterBase::ACharacterBase()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ACharacterBase::BeginPlay()
{
    Super::BeginPlay();
    
    AssignCharacterAttributes();
}

void ACharacterBase::SetCharacterAttributes(float InHealth, float InAttackStrength, float InSpeed)
{
    Health = InHealth;
    AttackStrength = InAttackStrength;
    Speed = InSpeed;
}

void ACharacterBase::AssignCharacterAttributes()
{
    FString TagString = CharacterClassTag.ToString();

    if (TagString == "Character.Warrior")
    {
        SetCharacterAttributes(200.f, 50.f, 300.f);
    }
    else if (TagString == "Character.Mage")
    {
        SetCharacterAttributes(100.f, 80.f, 250.f);
    }
    else if (TagString == "Character.Archer")
    {
        SetCharacterAttributes(120.f, 60.f, 280.f);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Unknown character class! Default attributes assigned."));
        SetCharacterAttributes(150.f, 40.f, 275.f);
    }
}

void ACharacterBase::Attack()
{
    UE_LOG(LogTemp, Warning, TEXT("Default attack"));
}
