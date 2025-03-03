#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "WizardCharacter.generated.h"

UCLASS()
class UTHUB_GAS2025_API AWizardCharacter : public ACharacterBase
{
    GENERATED_BODY()

public:
    AWizardCharacter();

    UPROPERTY(EditAnywhere, Blueprintable, Category = "Combat")
    TSubclassOf<AActor> MagicProjectileClass;

    virtual void Attack() override;

private:
    const float ATTACK_DISTANCE = 100.f;
    const float PROJECTILE_SPEED = 1000.f;
};
