#pragma once
#include "AnimalCookingEvent.h"

class UtensilBecomesDirtyEvent : public AnimalCookingEvent {
public:
	UtensilBecomesDirtyEvent();
	~UtensilBecomesDirtyEvent();

	virtual std::string toJson() override;
private:
};

