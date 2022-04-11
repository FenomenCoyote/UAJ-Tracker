#include "pch.h"
#include "LevelEndEvent.h"

LevelEndEvent::LevelEndEvent(): _levelWin(false)
{
}

LevelEndEvent::~LevelEndEvent()
{
}

bool LevelEndEvent::getLevelWin() const
{
	return _levelWin;
}

void LevelEndEvent::setLevelWin(bool lW)
{
	_levelWin = lW;
}
