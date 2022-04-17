#include "pch.h"
#include "IPersistance.h"
#include "ISerializer.h"

IPersistance::IPersistance(ISerializer* s): _serializer(s)
{
}

void IPersistance::setSerializer(ISerializer* serializer)
{
	_serializer = serializer;
}
