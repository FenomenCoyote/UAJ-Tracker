#include "UtensilCleanEvent.h"

UtensilCleanEvent::UtensilCleanEvent() : AnimalCookingEvent()
{
	_myType = "UtensilCleanEvent";
}

UtensilCleanEvent::~UtensilCleanEvent()
{
}

std::string UtensilCleanEvent::toJson()
{
	return AnimalCookingEvent::toJson() + "},";
}
