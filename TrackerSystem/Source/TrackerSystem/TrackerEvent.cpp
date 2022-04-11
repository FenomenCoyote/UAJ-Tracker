#include "pch.h"
#include "TrackerEvent.h"

TrackerEvent::TrackerEvent(): _timeStamp(0), _userId(0), _sessionId(0), _gameId(0), _eventId(0)
{
}

TrackerEvent::~TrackerEvent()
{
}

std::string TrackerEvent::toJson()
{
	return "potatoe\n";
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
