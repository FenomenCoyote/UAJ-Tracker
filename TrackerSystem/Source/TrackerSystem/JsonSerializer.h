#pragma once
#include "ISerializer.h"

class DllExport JsonSerializer: public ISerializer
{
public:

	virtual std::string serialize(TrackerEvent* e);
};

