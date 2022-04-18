#include "pch.h"
#include "ServerPersistance.h"
#include "TrackerEvent.h"
#include "ISerializer.h"
#include "curl/curl.h"

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

		std::string json = _serializer->serialize(e);
		json[json.length() - 1] = ' ';

		auto curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, "http://uaj.fdi.ucm.es/c2122/telemetry/grupo03");

			struct curl_slist* chunk = NULL;

			chunk = curl_slist_append(chunk, "x-api-key: 54520efb6f9e255c78ef58becc7c5b7f");
			chunk = curl_slist_append(chunk, "Content-Type: application/json");

			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json.c_str());
			curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, -1L);

			CURLcode result = curl_easy_perform(curl);

			if (result != CURLE_OK) {
				std::cout << "error in HTTP result: " << result << '\n';
			}

			curl_easy_cleanup(curl);
			curl = NULL;
		}

		delete e;
	}
}