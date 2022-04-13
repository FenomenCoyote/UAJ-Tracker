#include "pch.h"

#include "JsonSerializer.h"
#include "TrackerEvent.h"

JsonSerializer::JsonSerializer()
{
	/*Writer<StringBuffer> writer(s);
	writer.StartObject();*/
}

JsonSerializer::~JsonSerializer()
{
	//writer.EndObject();	
}

std::string JsonSerializer::serialize(TrackerEvent* e)
{
	return e->toJson() + "\n";
}