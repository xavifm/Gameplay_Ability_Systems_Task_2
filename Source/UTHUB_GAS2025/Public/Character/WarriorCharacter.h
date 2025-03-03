#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "WarriorCharacter.generated.h"

UCLASS()
class UTHUB_GAS2025_API AWarriorCharacter : public ACharacterBase
{
	GENERATED_BODY()
	
public:
	AWarriorCharacter();

	virtual void Attack() override;

private:
	const float ATTACK_DISTANCE = 200.f;
	const float ATTACK_RADIUS = 150.f;
};
