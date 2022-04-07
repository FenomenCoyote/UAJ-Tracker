#include "pch.h"
#include "DishFinishedEvent.h"

DishFinishedEvent::DishFinishedEvent() : _result(false)
{
}

DishFinishedEvent::~DishFinishedEvent()
{
}

inline bool DishFinishedEvent::getResult() const
{
	return false;
}

inline void DishFinishedEvent::setResult(bool m)
{
}
