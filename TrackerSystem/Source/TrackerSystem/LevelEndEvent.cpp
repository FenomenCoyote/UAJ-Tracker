#include "pch.h"
#include "LevelEndEvent.h"

LevelEndEvent::LevelEndEvent(): _levelWin(false)
{
	_myType = "LevelEndEvent";
}

LevelEndEvent::~LevelEndEvent()
{
}

std::string LevelEndEvent::toJson()
{
	return GameEvent::toJson() + ",\"levelWin\":" + std::to_string(_levelWin) + "},";
}

bool LevelEndEvent::getLevelWin() const
{
	return _levelWin;
}

void LevelEndEvent::setLevelWin(bool lW)
{
	_levelWin = lW;
}
