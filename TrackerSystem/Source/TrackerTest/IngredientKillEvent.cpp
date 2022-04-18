#include "IngredientKillEvent.h"

IngredientKillEvent::IngredientKillEvent() : GameEvent(), _mistake(false)
{
	_myType = "IngredientKillEvent";
}

IngredientKillEvent::~IngredientKillEvent()
{
}

std::string IngredientKillEvent::toJson()
{
	if(_mistake)
		return GameEvent::toJson() + ",\"mistake\":true },";
	return GameEvent::toJson()  + ",\"mistake\":false },";
}

