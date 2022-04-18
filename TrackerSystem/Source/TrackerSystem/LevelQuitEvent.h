#pragma once
#include "GameEvent.h"

class DllExport LevelQuitEvent : public GameEvent {
public:
	LevelQuitEvent();
	~LevelQuitEvent();

	virtual std::string toJson() override;
private:
};

