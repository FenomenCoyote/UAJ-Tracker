#pragma once
#include "TrackerEvent.h"
#include "defines.h"

class DllExport GameEvent: public TrackerEvent{
public:
	GameEvent();
	~GameEvent();

	uint16_t getLevelId() const;

	void setLevelId(uint16_t lI);
private:
	uint16_t _levelId;
};

