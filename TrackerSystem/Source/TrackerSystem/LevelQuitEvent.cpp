#include "pch.h"
#include "LevelQuitEvent.h"

LevelQuitEvent::LevelQuitEvent()
{
	_myType = "LevelQuitEvent";
}

LevelQuitEvent::~LevelQuitEvent()
{
}

std::string LevelQuitEvent::toJson()
{
	return GameEvent::toJson() + "},";
}
