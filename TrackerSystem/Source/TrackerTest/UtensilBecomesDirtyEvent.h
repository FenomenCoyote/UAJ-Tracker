#pragma once
#include "GameEvent.h"

class UtensilBecomesDirtyEvent : public GameEvent {
public:
	UtensilBecomesDirtyEvent(int a);
	~UtensilBecomesDirtyEvent();
private:
};

