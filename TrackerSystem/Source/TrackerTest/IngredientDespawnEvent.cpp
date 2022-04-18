#include "IngredientDespawnEvent.h"

IngredientDespawnEvent::IngredientDespawnEvent() : GameEvent()
{
	_myType = "IngredientDespawnEvent";
}

IngredientDespawnEvent::~IngredientDespawnEvent()
{
}

std::string IngredientDespawnEvent::toJson()
{
	return GameEvent::toJson() + "},";
}
