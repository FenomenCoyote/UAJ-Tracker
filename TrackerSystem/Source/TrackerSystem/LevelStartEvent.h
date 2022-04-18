#pragma once
#include "GameEvent.h"

class DllExport LevelStartEvent : public GameEvent {
public:
	LevelStartEvent();
	~LevelStartEvent();

	virtual std::string toJson() override;
private:
};

