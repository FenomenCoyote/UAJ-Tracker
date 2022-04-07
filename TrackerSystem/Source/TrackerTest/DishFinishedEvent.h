#pragma once
#include "GameEvent.h"

class DishFinishedEvent : public GameEvent {
public:
	DishFinishedEvent();
	~DishFinishedEvent();

	inline bool getResult() const;

	inline void setResult(bool m);
private:
	bool _result;
};

