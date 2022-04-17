#pragma once
#include "TrackerEvent.h"

class AnimalCookingEvent: public TrackerEvent {
public:
	AnimalCookingEvent();
	~AnimalCookingEvent();
	virtual std::string toJson();

	inline AnimalCookingEvent setLevelId(uint16_t level) {
		_levelId = level;
	}
	inline AnimalCookingEvent setType(std::string eventType) {
		_myType = eventType;
	}

protected:
	std::string _myType;
	uint16_t _levelId;
};

