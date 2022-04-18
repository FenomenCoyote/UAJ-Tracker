#include "DirtyUtensilsAttackEvent.h"

DirtyUtensilsAttackEvent::DirtyUtensilsAttackEvent() : AnimalCookingEvent()
{
	_myType = "DirtyUtensilsAttackEvent";
}

DirtyUtensilsAttackEvent::~DirtyUtensilsAttackEvent()
{
}

std::string DirtyUtensilsAttackEvent::toJson()
{
	return  AnimalCookingEvent::toJson() + "},";
}
