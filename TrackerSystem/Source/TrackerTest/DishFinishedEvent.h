#pragma once
#include "GameEvent.h"

class DishFinishedEvent : public GameEvent {
public:
	DishFinishedEvent();
	~DishFinishedEvent();

	bool getResult() const;

	void setResult(bool m);
private:
	bool _result;
};

