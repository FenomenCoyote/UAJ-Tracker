#include "pch.h"
#include "LevelQuitEvent.h"

LevelQuitEvent::LevelQuitEvent()
{
	setEventId(3);
}

LevelQuitEvent::~LevelQuitEvent()
{
}

std::string LevelQuitEvent::toJson()
{
	return GameEvent::toJson() + "},";
}
