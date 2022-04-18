#include "IngredientDespawnEvent.h"

IngredientDespawnEvent::IngredientDespawnEvent() : AnimalCookingEvent()
{
	_myType = "IngredientDespawnEvent";
}

IngredientDespawnEvent::~IngredientDespawnEvent()
{
}

std::string IngredientDespawnEvent::toJson()
{
	return AnimalCookingEvent::toJson() + "},";
}
