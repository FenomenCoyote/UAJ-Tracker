#include "pch.h"
#include "LevelStartEvent.h"

LevelStartEvent::LevelStartEvent()
{
	setEventId(1);
}

LevelStartEvent::~LevelStartEvent()
{
}

std::string LevelStartEvent::toJson()
{
	return GameEvent::toJson() + "},";
}
