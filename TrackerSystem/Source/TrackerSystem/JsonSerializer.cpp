#include "pch.h"

#include "JsonSerializer.h"
#include "TrackerEvent.h"

std::string JsonSerializer::serialize(TrackerEvent* e)
{
	return e->toJson();
}
