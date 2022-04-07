#include "pch.h"
#include "GameEvent.h"

GameEvent::GameEvent(): _levelId(0)
{
}

GameEvent::~GameEvent()
{
}

inline uint16_t GameEvent::getLevelId() const
{
	return _levelId;
}

inline void GameEvent::setLevelId(uint16_t lI)
{
	_levelId = lI;
}
