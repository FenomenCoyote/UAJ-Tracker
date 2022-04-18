#include "pch.h"

#include "JsonSerializer.h"
#include "TrackerEvent.h"

std::string JsonSerializer::serialize(TrackerEvent* e)
{
	std::string output = e->toJson() + "\n";
	return output;
	//return  e->toJson() + "\n";	
}

std::string JsonSerializer::startSyntax()
{
	return "[\n";
}

std::string JsonSerializer::endSyntax()
{
	return "\n]";
}
