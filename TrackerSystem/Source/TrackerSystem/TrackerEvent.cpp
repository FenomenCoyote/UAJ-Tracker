#include "pch.h"
#include "TrackerEvent.h"

using namespace rapidjson;

TrackerEvent::TrackerEvent(): _timeStamp(0), _userId(0), _sessionId(0), _gameId(0), _eventId(0)
{
}

TrackerEvent::~TrackerEvent()
{
}

std::string TrackerEvent::toJson()
{  
    //METHOD1 
    //StringBuffer s;
    //Writer<StringBuffer> writer(s);    
    //writer.StartObject();             
    //writer.Key("timeStamp");              
    //writer.Int(_timeStamp);           

    //writer.Key("eventId");
    //writer.Uint(_eventId);

    //writer.Key("gameId");
    //writer.Uint(1);

    //writer.Key("userId");
    //writer.Uint64(245);

    //writer.Key("sessionId");
    //writer.Int(_sessionId);
 
    //writer.EndObject();    
    //std::cout << s.GetString() << std::endl;    
    //return s.GetString();

    //METHOD2 
    //const char* json = "{ \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] }"; 
    //printf("Original JSON:\n %s\n", json);
    //return json;

    //METHOD3
    std::string json = "\"timeStamp\":" + std::to_string(_timeStamp) +        
        ",\"userId\":" + std::to_string(_userId) +
        ",\"sessionId\":" + std::to_string(_sessionId) +
        ",\"gameId\":" + std::to_string(_gameId) +
        ",\"eventId\":" + std::to_string(_eventId) ;
    return json;
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

uint8_t TrackerEvent::getEventId() const
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

void TrackerEvent::setEventId(uint8_t eI)
{
	_eventId = eI;
}
