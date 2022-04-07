#pragma once
#include "pch.h"
#include "GameEvent.h"

class LevelEndEvent : public GameEvent {
public:
	LevelEndEvent();
	~LevelEndEvent();

	inline bool getLevelWin() const;

	inline void setLevelWin(bool lW);
private:
	bool _levelWin;
};

