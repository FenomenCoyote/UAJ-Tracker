#include "pch.h"
#include "SessionStartEvent.h"

SessionStartEvent::SessionStartEvent()
{
	_myType = "SessionStartEvent";
}

SessionStartEvent::~SessionStartEvent()
{
}

std::string SessionStartEvent::toJson()
{
	return TrackerEvent::toJson() + "},";
}
