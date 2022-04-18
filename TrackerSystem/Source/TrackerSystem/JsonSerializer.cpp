#include "pch.h"

#include "JsonSerializer.h"
#include "TrackerEvent.h"

std::string JsonSerializer::serialize(TrackerEvent* e)
{
	std::string output = e->toJson() + "\n";
	return output;	
}

std::string JsonSerializer::startSyntax()
{
	//Al ser json, los eventos se meten en un array
	return "[\n";
}

std::string JsonSerializer::endSyntax()
{
	//Al ser json, los eventos se meten en un array
	return "\n]";
}
