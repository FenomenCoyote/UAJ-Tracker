#pragma once
#include "ISerializer.h"
#include <iostream>
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

class DllExport JsonSerializer: public ISerializer
{
public:
	JsonSerializer();
	~JsonSerializer();
	virtual std::string serialize(TrackerEvent* e);
private:
	StringBuffer s;
	Writer<StringBuffer> writer;
};

