#include "DishFinishedEvent.h"

DishFinishedEvent::DishFinishedEvent() : AnimalCookingEvent(), _result(false)
{
	_myType = "DishFinishedEvent";
}

DishFinishedEvent::~DishFinishedEvent()
{
}

std::string DishFinishedEvent::toJson()
{
	if (_result)
		return AnimalCookingEvent::toJson() + ",\"result\": true";
	return AnimalCookingEvent::toJson() + ",\"result\": false";
}

