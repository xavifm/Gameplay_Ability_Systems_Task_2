#include "Character/WarriorCharacter.h"
#include "Kismet/GameplayStatics.h"

AWarriorCharacter::AWarriorCharacter()
{
    CharacterClassTag = FGameplayTag::RequestGameplayTag(FName("Character.Warrior"));
}

void AWarriorCharacter::Attack()
{
    FVector AttackLocation = GetActorLocation() + GetActorForwardVector() * ATTACK_DISTANCE;

    TArray<AActor*> HitActors;
    UGameplayStatics::ApplyRadialDamage(GetWorld(), AttackStrength, AttackLocation, ATTACK_RADIUS, nullptr, HitActors, this);
}