#include "pch.h"
#include "SessionEndEvent.h"

SessionEndEvent::SessionEndEvent()
{
	_myType = "SessionEndEvent";
}

SessionEndEvent::~SessionEndEvent()
{
}

std::string SessionEndEvent::toJson()
{
	return TrackerEvent::toJson() + "}";
}
