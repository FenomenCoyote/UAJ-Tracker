#pragma once
#include "GameEvent.h"

class IngredientKillEvent : public GameEvent {
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

