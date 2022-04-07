#pragma once
#include "ISerializer.h"

class JsonSerializer: public ISerializer
{
public:

	virtual std::string serialize(TrackerEvent* e);
};

