#include "pch.h"
#include "SessionEndEvent.h"

SessionEndEvent::SessionEndEvent()
{
	setEventId(255);
}

SessionEndEvent::~SessionEndEvent()
{
}

std::string SessionEndEvent::toJson()
{
	return TrackerEvent::toJson() + "}";
}
