#include "pch.h"

#include "FilePersistance.h"
#include "TrackerEvent.h"
#include "ISerializer.h"

FilePersistance::FilePersistance(ISerializer* s, char* filePath): IPersistance(s), _filePath(filePath), _eventQueue1(), _eventQueue2(), _flushRequested(false), _threadActive(true)
{
	_activeQueue = &_eventQueue1;
	
	FILE* file;
	fopen_s(&file, _filePath, "a");
	std::string aux = s->startSyntax();
	fwrite(aux.c_str(), aux.length(), 1, file);
	fclose(file);

	_thread = new std::thread(&FilePersistance::flushQueue, this);
}

FilePersistance::~FilePersistance()
{
	_threadActive = false;

	_thread->join();

	if (!_eventQueue1.empty())
		writeQueue(_eventQueue1);
	if (!_eventQueue2.empty())
		writeQueue(_eventQueue2);

	FILE* file;
	fopen_s(&file, _filePath, "a");
	std::string aux = _serializer->endSyntax();
	fwrite(aux.c_str(), aux.length(), 1, file);
	fclose(file);

	delete _filePath;
}

void FilePersistance::send(TrackerEvent* e)
{
	_activeQueue->push(e);
}

void FilePersistance::flush()
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

void FilePersistance::setPath(char* path)
{
	delete _filePath;
	_filePath = path;
}

void FilePersistance::flushQueue()
{
	while (_threadActive) {
		if (_flushRequested) {
			if (_activeQueue == &_eventQueue2)
				writeQueue(_eventQueue1);
			else 
				writeQueue(_eventQueue2);

			_flushRequested = false;
		}
	}
}

void FilePersistance::writeQueue(std::queue<TrackerEvent*>& queue)
{
	FILE* file;
	fopen_s(&file,_filePath, "a");

	while (!queue.empty()) {
		TrackerEvent* e = queue.front();	queue.pop();

		std::string aux = _serializer->serialize(e);
		
		fwrite(aux.c_str(), aux.length(), 1, file);

		delete e;
	}

	fclose(file);
}


