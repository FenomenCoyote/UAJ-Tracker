#include "IngredientKillEvent.h"

IngredientKillEvent::IngredientKillEvent(): AnimalCookingEvent(), _mistake(false)
{
	_myType = "IngredientKillEvent";
}

IngredientKillEvent::~IngredientKillEvent()
{
}

std::string IngredientKillEvent::toJson()
{
	if(_mistake)
		return AnimalCookingEvent::toJson() + ",\"mistake\":true";
	return AnimalCookingEvent::toJson()  + ",\"mistake\":false";
}

