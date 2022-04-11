#pragma once
#include "GameEvent.h"

class DllExport LevelEndEvent : public GameEvent {
public:
	LevelEndEvent();
	~LevelEndEvent();

	bool getLevelWin() const;

	void setLevelWin(bool lW);
private:
	bool _levelWin;
};

