#include "UtensilBecomesDirtyEvent.h"

UtensilBecomesDirtyEvent::UtensilBecomesDirtyEvent() : AnimalCookingEvent()
{
	_myType = "UtensilBecomesDirtyEvent";
}

UtensilBecomesDirtyEvent::~UtensilBecomesDirtyEvent()
{
}

std::string UtensilBecomesDirtyEvent::toJson()
{
	return AnimalCookingEvent::toJson() + "},";
}
