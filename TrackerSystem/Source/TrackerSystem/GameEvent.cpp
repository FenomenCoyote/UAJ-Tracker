#include "pch.h"
#include "GameEvent.h"

GameEvent::GameEvent(): TrackerEvent(), _levelId(0)
{
}

GameEvent::~GameEvent()
{
}

std::string GameEvent::toJson()
{
	return TrackerEvent::toJson() + ",\"levelId\":" + std::to_string(_levelId);
}

uint16_t GameEvent::getLevelId() const
{
	return _levelId;
}

void GameEvent::setLevelId(uint16_t lI)
{
	_levelId = lI;
}
