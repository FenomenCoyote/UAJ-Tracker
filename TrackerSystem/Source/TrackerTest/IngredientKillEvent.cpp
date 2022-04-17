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

bool IngredientKillEvent::getMistake() const
{
	return _mistake;
}

void IngredientKillEvent::setMistake(bool m)
{
	_mistake = m;
}
