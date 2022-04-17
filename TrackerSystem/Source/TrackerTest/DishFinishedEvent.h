#pragma once
#include "AnimalCookingEvent.h"

class DishFinishedEvent : public AnimalCookingEvent {
public:
	DishFinishedEvent();
	~DishFinishedEvent();
	virtual std::string toJson() override;

	bool getResult() const { return _result; };

	AnimalCookingEvent* setResult(bool m) {
		_result = m;
		return this;
	}
private:
	bool _result;
};

