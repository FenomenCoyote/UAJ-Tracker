#pragma once
#include "IPersistance.h"
#include <queue>
#include <thread> 
#include <atomic>

class FilePersistance : public IPersistance
{
public:

	FilePersistance(ISerializer* s, char* filePath);
	~FilePersistance();

	virtual void send(TrackerEvent* e);
	virtual void flush();

private:
	const int CHAR_EXTRA_SPACE = 3;

	char* _filePath;
	std::atomic<bool> _flushRequested;
	std::atomic<bool> _threadActive;

	std::queue<TrackerEvent*>* _activeQueue;
	std::queue<TrackerEvent*> _eventQueue1;
	std::queue<TrackerEvent*> _eventQueue2;

	std::thread* _thread;

	void flushQueue();
	void writeQueue(std::queue<TrackerEvent*> queue);
};

