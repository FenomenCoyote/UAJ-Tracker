#pragma once
#include "GameEvent.h"

class IngredientDespawnEvent : public GameEvent {
public:
	IngredientDespawnEvent();
	~IngredientDespawnEvent();

	virtual std::string toJson() override;
private:
};

