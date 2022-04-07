#include "pch.h"
#include "IngredientKillEvent.h"

IngredientKillEvent::IngredientKillEvent(): _mistake(false)
{
}

IngredientKillEvent::~IngredientKillEvent()
{
}

inline bool IngredientKillEvent::getMistake() const
{
	return _mistake;
}

inline void IngredientKillEvent::setMistake(bool m)
{
	_mistake = m;
}
