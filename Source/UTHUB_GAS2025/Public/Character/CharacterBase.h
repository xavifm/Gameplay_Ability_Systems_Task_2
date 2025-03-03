#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "CharacterBase.generated.h"

UCLASS()
class UTHUB_GAS2025_API ACharacterBase : public ACharacter
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

public:
    ACharacterBase();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
    FGameplayTag CharacterClassTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    float Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    float AttackStrength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    float Speed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    UAnimMontage* AttackAnimation;


    UFUNCTION(BlueprintCallable, Category = "Combat")
    virtual void Attack();
    
private:    
    void SetCharacterAttributes(float InHealth, float InAttackStrength, float InSpeed);
    void AssignCharacterAttributes();
};

