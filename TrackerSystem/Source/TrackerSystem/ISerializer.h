#pragma once
#include <string>

class TrackerEvent;

class ISerializer
{
public:

	virtual std::string serialize(TrackerEvent* e) = 0;
};

