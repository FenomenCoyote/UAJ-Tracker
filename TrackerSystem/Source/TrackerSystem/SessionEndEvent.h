#pragma once
#include "TrackerEvent.h"

class SessionEndEvent : public TrackerEvent {
public:
	SessionEndEvent();
	~SessionEndEvent();

	virtual std::string toJson() override;
private:
};