#include "DishFinishedEvent.h"

DishFinishedEvent::DishFinishedEvent() : GameEvent(), _result(false)
{
	_myType = "DishFinishedEvent";
}

DishFinishedEvent::~DishFinishedEvent()
{
}

std::string DishFinishedEvent::toJson()
{
	if (_result)
		return GameEvent::toJson() + ",\"result\": true },";
	return GameEvent::toJson() + ",\"result\": false },";
}

