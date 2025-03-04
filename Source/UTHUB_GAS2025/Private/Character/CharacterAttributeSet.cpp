#include "Character/CharacterAttributeSet.h"

UCharacterAttributeSet::UCharacterAttributeSet()
{
    Health.SetBaseValue(MAX_HEALTH);
    Health.SetCurrentValue(MAX_HEALTH);
}
