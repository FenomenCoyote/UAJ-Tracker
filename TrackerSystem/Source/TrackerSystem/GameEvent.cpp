#include "pch.h"
#include "GameEvent.h"

GameEvent::GameEvent(): _levelId(0)
{
}

GameEvent::~GameEvent()
{
}

uint16_t GameEvent::getLevelId() const
{
	return _levelId;
}

void GameEvent::setLevelId(uint16_t lI)
{
	_levelId = lI;
}
