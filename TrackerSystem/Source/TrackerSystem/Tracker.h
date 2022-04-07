#pragma once
#include <iostream>
#include <cassert>
#include <string>
#include <thread>
#include <mutex>
#include <queue>
#include <array>


class IPersistance;
class TrackerEvent;

class Tracker
{
private:
	static Tracker* instance;
public:

	/**
	 * Inits system
	 * @return true when all good
	 * @return false when something bad happened
	 */
	static bool Init();

	inline static Tracker* Instance() {
		assert(instance != nullptr);
		return instance;
	}

	/**
	 * 
	 * @param userNameID 
	 */
	void setUserID(const std::string& userNameID);

	/**
	 * Game ID 
	 * @param gameID int
	 */
	void setGameID(const int gameID) { this->gameID = gameID; }

	/**
	 * Where to store data
	 * @param path 
	 */
	void setStoragePath(const std::string& path);

	/**
	 * Start of session
	 * @return true 
	 * @return false 
	 */
	bool Start();

	/**
	 * End of session
	 * @return true 
	 * @return false 
	 */
	bool End();

	template<typename T = TrackerEvent, typename ...Targs>
	void trackEvent(Targs&&... args) {
		TrackerEvent* te = new T(std::forward<Targs>(args)...);

		if (te != nullptr) {
			te->setTimeStamp(getTimestamp());
			te->setGameId(gameID);
			te->setSessionId(sessionID);

			//TODO: string OR unsigned long int
			te->setUserId(userID);
		}

		persistance->send(te);
	}

private:

	Tracker(); 

	~Tracker(); 
	
	/**
	* time_t == long long
	*/
	std::time_t getTimestamp();

	std::string path;

	std::string userID;
	
	int gameID;
	int sessionID;

	IPersistance* persistance;
};

