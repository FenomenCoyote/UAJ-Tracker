#pragma once
#include "GameEvent.h"

class IngredientKillEvent : public GameEvent {
public:
	IngredientKillEvent();
	~IngredientKillEvent();

	inline bool getMistake() const;

	inline void setMistake(bool m);
private:
	bool _mistake;
};

