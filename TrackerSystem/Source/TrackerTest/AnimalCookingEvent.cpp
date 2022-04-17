#include "pch.h"
#include "AnimalCookingEvent.h"

AnimalCookingEvent::AnimalCookingEvent(): TrackerEvent(), _levelId(0)
{

}

AnimalCookingEvent::~AnimalCookingEvent()
{
}

std::string AnimalCookingEvent::toJson()
{
	return TrackerEvent::toJson() + ",\"_levelId\":" + std::to_string(_levelId) + ",\"_myType\": " +  "\"" +_myType + "\"";
}

