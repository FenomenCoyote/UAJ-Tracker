#pragma once
#include <iostream>
#include <chrono>
#include "defines.h"

/* 
userId: 
	- 2 bytes: user code
	- 6 bytes: mac code (12 hexadecimal - 4 bits per hexadecimal)

sessionId:	
	- 2 bytes: 65.500 sessions aprox (1 time every day during 178 years) SessionId:
	- 2 bytes: 65.500 sessions aprox (1 time every day during 178 years)

gameId:
	- 1 byte: 255 differents games

json structure: timeStamp, eventId, gameId, userId, sessionId
*/

class DllExport TrackerEvent {
public:
	TrackerEvent();
	~TrackerEvent();
	std::string toJson();
	
	int getTimeStamp() const;
	uint64_t getUserId() const;
	unsigned short int getSessionId() const;
	uint8_t getGameId() const;
	uint16_t getEventId() const;

	void setTimeStamp(int tS);
	void setUserId(uint64_t uI);
	void setSessionId(unsigned short int sI);
	void setGameId(uint8_t gI);
	void setEventId(uint16_t eI);
private:
	int _timeStamp;
	uint64_t _userId;
	unsigned short int _sessionId;
	uint8_t _gameId;
	uint16_t _eventId;
};