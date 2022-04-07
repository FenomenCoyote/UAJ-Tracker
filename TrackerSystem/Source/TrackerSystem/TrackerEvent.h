#pragma once
#include <iostream>
#include <chrono>

/* 
userId: 
	- 2 bytes: user code
	- 6 bytes: mac code (12 hexadecimal - 4 bits per hexadecimal)

sessionId:	
	- 2 bytes: 65.500 sessions aprox (1 time every day during 178 years) SessionId:
	- 2 bytes: 65.500 sessions aprox (1 time every day during 178 years)

gameId:
	- 1 byte: 255 differents games
*/

class TrackerEvent {
public:
	TrackerEvent();
	~TrackerEvent();
	bool toJson();
	
	inline int getTimeStamp() const;
	inline unsigned long int getUserId() const;
	inline unsigned short int getSessionId() const;
	inline uint8_t getGameId() const;
	inline uint16_t getEventId() const;

	inline void setTimeStamp(int tS);
	inline void setUserId(unsigned long int uI);
	inline void setSessionId(unsigned short int sI);
	inline void setGameId(uint8_t gI);
	inline void setEventId(uint16_t eI);
private:
	int _timeStamp;
	unsigned long int _userId;
	unsigned short int _sessionId;
	uint8_t _gameId;
	uint16_t _eventId;
};