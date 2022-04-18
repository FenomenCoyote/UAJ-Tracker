#pragma once
#include "AnimalCookingEvent.h"

class DirtyUtensilsAttackEvent : public AnimalCookingEvent {
public:
	DirtyUtensilsAttackEvent();
	~DirtyUtensilsAttackEvent();

	virtual std::string toJson();
private:
};

