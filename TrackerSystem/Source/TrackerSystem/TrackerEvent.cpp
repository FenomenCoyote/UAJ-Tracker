#include "pch.h"
#include "TrackerEvent.h"
#include <iostream>
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

TrackerEvent::TrackerEvent(): _timeStamp(0), _userId(0), _sessionId(0), _gameId(0), _eventId(0)
{
}

TrackerEvent::~TrackerEvent()
{
}

std::string TrackerEvent::toJson()
{  
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    //json structure : timeStamp, eventId, gameId, userId, sessionId
    writer.StartObject();              // Between StartObject()/EndObject(), 
    writer.Key("timeStamp");                // output a key,
    writer.Int(_timeStamp);             // follow by a value.

    writer.Key("eventId");
    writer.Uint(_eventId);

    writer.Key("gameId");
    writer.Uint(1);

    writer.Key("userId");
    writer.Uint64(245);

    writer.Key("sessionId");
    writer.Int(_sessionId);
 
    writer.EndObject();    
    std::cout << s.GetString() << std::endl;    
    return s.GetString();

 /*   const char* json = " { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] } ";
    printf("Original JSON:\n %s\n", json);
    return json;*/
}

int TrackerEvent::getTimeStamp() const
{
	return _timeStamp;
}

uint64_t TrackerEvent::getUserId() const
{
	return _userId;
}

unsigned short int TrackerEvent::getSessionId() const
{
	return _sessionId;
}

uint8_t TrackerEvent::getGameId() const
{
	return _gameId;
}

uint16_t TrackerEvent::getEventId() const
{
	return _eventId;
}


void TrackerEvent::setTimeStamp(int tS)
{
	_timeStamp = tS;
}

void TrackerEvent::setUserId(uint64_t uI)
{
	_userId = uI;
}

void TrackerEvent::setSessionId(unsigned short int sI)
{
	_sessionId = sI;
}

void TrackerEvent::setGameId(uint8_t gI)
{
	_gameId = gI;
}

void TrackerEvent::setEventId(uint16_t eI)
{
	_eventId = eI;
}
