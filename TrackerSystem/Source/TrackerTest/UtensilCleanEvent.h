#pragma once
#include "AnimalCookingEvent.h"

class UtensilCleanEvent : public AnimalCookingEvent {
public:
	UtensilCleanEvent();
	~UtensilCleanEvent();

	virtual std::string toJson() override;
private:
};

