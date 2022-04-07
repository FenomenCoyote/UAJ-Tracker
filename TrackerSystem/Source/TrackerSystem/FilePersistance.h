#pragma once
#include "IPersistance.h"
#include <queue>
#include <thread> 
#include <mutex>          // std::mutex


class FilePersistance : public IPersistance
{
public:

	FilePersistance(ISerializer* s, char* filePath);

	virtual void send(TrackerEvent* e);
	virtual void flush();

private:
	char* _filePath;
	bool _flushRequested;

	std::queue<TrackerEvent*>* _activeQueue;
	std::queue<TrackerEvent*> _eventQueue1;
	std::queue<TrackerEvent*> _eventQueue2;

	std::thread* _thread;
	std::mutex mtx;

	void flushQueue();
	void writeQueue(std::queue<TrackerEvent*> queue);
};

