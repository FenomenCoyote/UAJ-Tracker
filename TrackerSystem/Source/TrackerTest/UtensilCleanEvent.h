#pragma once
#include "GameEvent.h"

class UtensilCleanEvent : public GameEvent {
public:
	UtensilCleanEvent();
	~UtensilCleanEvent();

	virtual std::string toJson() override;
private:
};

