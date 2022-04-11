#pragma once
#include "GameEvent.h"

class IngredientKillEvent : public GameEvent {
public:
	IngredientKillEvent();
	~IngredientKillEvent();

	bool getMistake() const;

	void setMistake(bool m);
private:
	bool _mistake;
};

