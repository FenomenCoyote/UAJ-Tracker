#pragma once
#include "GameEvent.h"

class UtensilBecomesDirtyEvent : public GameEvent {
public:
	UtensilBecomesDirtyEvent();
	~UtensilBecomesDirtyEvent();

	virtual std::string toJson() override;
private:
};

