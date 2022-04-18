#include "pch.h"
#include "LevelStartEvent.h"

LevelStartEvent::LevelStartEvent()
{
	_myType = "LevelStartEvent";
}

LevelStartEvent::~LevelStartEvent()
{
}

std::string LevelStartEvent::toJson()
{
	return GameEvent::toJson() + "},";
}
