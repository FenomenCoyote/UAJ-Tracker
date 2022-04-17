#pragma once
#include "AnimalCookingEvent.h"

class IngredientKillEvent : public AnimalCookingEvent {
public:
	IngredientKillEvent();
	~IngredientKillEvent();
	virtual std::string toJson() override;
	
	bool getMistake() const {
		return _mistake;
	}

	IngredientKillEvent* setMistake(bool m) {
		_mistake = m;
		return this;
	}
private:
	bool _mistake;
};

