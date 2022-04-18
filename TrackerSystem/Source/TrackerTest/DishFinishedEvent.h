#pragma once
#include "GameEvent.h"

class DishFinishedEvent : public GameEvent {
public:
	DishFinishedEvent();
	~DishFinishedEvent();
	virtual std::string toJson() override;

	bool getResult() const { return _result; };

	DishFinishedEvent* setResult(bool m) {
		_result = m;
		return this;
	}
private:
	bool _result;
};

