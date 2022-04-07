#include "pch.h"

#include "FilePersistance.h"
#include "TrackerEvent.h"
#include "ISerializer.h"

FilePersistance::FilePersistance(ISerializer* s, char* filePath): IPersistance(s), _filePath(filePath), _eventQueue1(), _eventQueue2(), _thread(), _flushRequested(false)
{
	_activeQueue = &_eventQueue1;
}

void FilePersistance::send(TrackerEvent* e)
{
	_activeQueue->push(e);
}

void FilePersistance::flush()
{
	bool isFlushing = false;

	mtx.lock();
	isFlushing = _flushRequested;
	_flushRequested = true;
	mtx.unlock();

	//si la cola esta realizando flush no se puede realizar otro para evitar que haya parones de ejecucion
	if (isFlushing)	
		return;	
}

//TODO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void FilePersistance::flushQueue()
{
	while (true) {
		if (_flushRequested) {
			if (_activeQueue == &_eventQueue1) {
				_activeQueue = &_eventQueue2;
				writeQueue(_eventQueue1);
			}
			else {
				_activeQueue = &_eventQueue1;
				writeQueue(_eventQueue2);
			}
		}
	}
}

void FilePersistance::writeQueue(std::queue<TrackerEvent*> queue)
{
	FILE* file;
	fopen_s(&file,_filePath, "a");

	while (!queue.empty()) {
		TrackerEvent* e = queue.front();	queue.pop();

		std::string aux = _serializer->serialize(e);
		char* buffer = new char[aux.length()];

		strcpy_s(buffer, aux.length(), aux.c_str());

		fwrite(&aux, aux.length(), 1, file);
	}
	fclose(file);
}


