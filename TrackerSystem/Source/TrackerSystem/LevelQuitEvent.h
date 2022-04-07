#pragma once
#include "pch.h"
#include "GameEvent.h"

class LevelQuitEvent : public GameEvent {
public:
	LevelQuitEvent();
	~LevelQuitEvent();
private:
};

