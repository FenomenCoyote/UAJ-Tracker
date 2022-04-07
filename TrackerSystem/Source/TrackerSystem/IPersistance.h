#pragma once

class TrackerEvent;
class ISerializer;

class IPersistance
{
public:
	IPersistance(ISerializer* s);

	virtual void send(TrackerEvent* e) = 0;
	virtual void flush() = 0;

	void setSerializer(ISerializer* serializer);

protected:
	ISerializer* _serializer;
};

