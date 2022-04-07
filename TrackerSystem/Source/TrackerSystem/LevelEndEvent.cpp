#include "pch.h"
#include "Test.h"
#include "LevelEndEvent.h"

LevelEndEvent::LevelEndEvent(): _levelWin(false)
{
}

LevelEndEvent::~LevelEndEvent()
{
}

inline bool LevelEndEvent::getLevelWin() const
{
	return _levelWin;
}

inline void LevelEndEvent::setLevelWin(bool lW)
{
	_levelWin = lW;
}
