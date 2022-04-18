#pragma once
#include "TrackerEvent.h"

class SessionStartEvent : public TrackerEvent {
public:
	SessionStartEvent();
	~SessionStartEvent();

	virtual std::string toJson() override;
private:
};