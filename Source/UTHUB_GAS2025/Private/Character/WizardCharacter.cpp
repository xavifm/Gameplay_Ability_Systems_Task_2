#include "Character/WizardCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include <GameplayTagContainer.h>
#include <Perception/AIPerceptionComponent.h>

AWizardCharacter::AWizardCharacter()
{
    CharacterClassTag = FGameplayTag::RequestGameplayTag(FName("Character.Mage"));
}

void AWizardCharacter::Attack()
{
    if (!MagicProjectileClass)
    {
        UE_LOG(LogTemp, Error, TEXT("MagicProjectileClass is not set!"));
        return;
    }

    FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * ATTACK_DISTANCE;
    FRotator SpawnRotation = GetActorRotation();

    AActor* SpawnedProjectile = GetWorld()->SpawnActor<AActor>(MagicProjectileClass, SpawnLocation, SpawnRotation);

    if (SpawnedProjectile)
    {
        UProjectileMovementComponent* ProjectileMovement = SpawnedProjectile->FindComponentByClass<UProjectileMovementComponent>();

        if (ProjectileMovement)
            ProjectileMovement->Velocity = GetActorForwardVector() * 1000.f;
    }
}
