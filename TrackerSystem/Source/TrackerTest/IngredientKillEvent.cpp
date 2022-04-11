#include "IngredientKillEvent.h"

IngredientKillEvent::IngredientKillEvent(): _mistake(false)
{
}

IngredientKillEvent::~IngredientKillEvent()
{
}

bool IngredientKillEvent::getMistake() const
{
	return _mistake;
}

void IngredientKillEvent::setMistake(bool m)
{
	_mistake = m;
}
