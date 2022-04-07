#pragma once
#include "pch.h"
#include "TrackerEvent.h"

class SessionEndEvent : public TrackerEvent {
public:
	SessionEndEvent();
	~SessionEndEvent();
private:
};