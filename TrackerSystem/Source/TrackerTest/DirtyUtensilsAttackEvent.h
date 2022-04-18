#pragma once
#include "GameEvent.h"

class DirtyUtensilsAttackEvent : public GameEvent {
public:
	DirtyUtensilsAttackEvent();
	~DirtyUtensilsAttackEvent();

	virtual std::string toJson();
private:
};

