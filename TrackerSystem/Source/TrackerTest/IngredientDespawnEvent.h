#pragma once
#include "AnimalCookingEvent.h"

class IngredientDespawnEvent : public AnimalCookingEvent {
public:
	IngredientDespawnEvent();
	~IngredientDespawnEvent();

	virtual std::string toJson() override;
private:
};

