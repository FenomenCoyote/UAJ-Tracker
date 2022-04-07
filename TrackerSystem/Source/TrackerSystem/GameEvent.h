#pragma once
#include "TrackerEvent.h"

class GameEvent: public TrackerEvent{
public:
	GameEvent();
	~GameEvent();

	inline uint16_t getLevelId() const;

	inline void setLevelId(uint16_t lI);
private:
	uint16_t _levelId;
};

