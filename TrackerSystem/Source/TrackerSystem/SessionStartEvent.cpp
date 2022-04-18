#include "pch.h"
#include "SessionStartEvent.h"

SessionStartEvent::SessionStartEvent()
{
	setEventId(0);
}

SessionStartEvent::~SessionStartEvent()
{
}

std::string SessionStartEvent::toJson()
{
	return TrackerEvent::toJson() + "},";
}
