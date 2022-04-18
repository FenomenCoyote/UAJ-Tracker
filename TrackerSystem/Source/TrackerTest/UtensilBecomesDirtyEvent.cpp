#include "UtensilBecomesDirtyEvent.h"

UtensilBecomesDirtyEvent::UtensilBecomesDirtyEvent() : GameEvent()
{
	_myType = "UtensilBecomesDirtyEvent";
}

UtensilBecomesDirtyEvent::~UtensilBecomesDirtyEvent()
{
}

std::string UtensilBecomesDirtyEvent::toJson()
{
	return GameEvent::toJson() + "},";
}
