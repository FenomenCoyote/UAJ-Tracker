#pragma once
#include <iostream>
#include <chrono>
#include "defines.h"
#include <iostream>
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <string>

class DllExport TrackerEvent {
public:
	TrackerEvent();
	~TrackerEvent();

	/// <summary>
	/// Dvuelve la clase en formato Json
	/// </summary>
	virtual std::string toJson();
	

	int getTimeStamp() const;
	uint64_t getUserId() const;
	unsigned short int getSessionId() const;
	uint8_t getGameId() const;

	void setTimeStamp(int tS);
	void setUserId(uint64_t uI);
	void setSessionId(unsigned short int sI);
	void setGameId(uint8_t gI);

private:
	int _timeStamp;
	uint64_t _userId;
	unsigned short int _sessionId;
	uint8_t _gameId;

protected:
	std::string _myType;
};