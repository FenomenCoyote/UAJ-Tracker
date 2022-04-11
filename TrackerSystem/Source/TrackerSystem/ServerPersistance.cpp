#include "pch.h"
#include "ServerPersistance.h"
#include "TrackerEvent.h"
#include "ISerializer.h"

#define X_KEY_PASSWORD "54520efb6f9e255c78ef58becc7c5b7f"

ServerPersistance::ServerPersistance(ISerializer* s, char* serverRoute) : IPersistance(s), _eventQueue1(), _eventQueue2(), _thread(), _flushRequested(false), _threadActive(true)
{
	_activeQueue = &_eventQueue1;

	_thread = new std::thread(&ServerPersistance::flushQueue, this);
}

ServerPersistance::~ServerPersistance()
{
	_threadActive = false;

	_thread->join();

	if (!_eventQueue1.empty())
		writeQueue(_eventQueue1);
	if (!_eventQueue2.empty())
		writeQueue(_eventQueue2);
}

void ServerPersistance::send(TrackerEvent* e)
{
	_activeQueue->push(e);
}

void ServerPersistance::flush()
{
	//si la cola esta realizando flush no se puede realizar otro para evitar que haya parones de ejecucion
	if (_flushRequested)
		return;

	_flushRequested = true;

	if (_activeQueue == &_eventQueue1)
		_activeQueue = &_eventQueue2;
	else
		_activeQueue = &_eventQueue1;
}

void ServerPersistance::flushQueue()
{
	while (_threadActive) {
		if (_flushRequested) {
			if (_activeQueue == &_eventQueue1)
				writeQueue(_eventQueue1);
			else
				writeQueue(_eventQueue2);

			_flushRequested = false;
		}
	}
}

void ServerPersistance::writeQueue(std::queue<TrackerEvent*>& queue)
{
	while (!queue.empty()) {
		TrackerEvent* e = queue.front();	queue.pop();

		std::string aux = _serializer->serialize(e);
		char* buffer = new char[aux.length() + CHAR_EXTRA_SPACE];
		strcpy_s(buffer, aux.length(), aux.c_str());



		delete buffer;
	}
}