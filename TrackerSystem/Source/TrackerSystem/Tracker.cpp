#include "pch.h"
#include "Tracker.h"
#include "TrackerEvent.h"
#include "IPersistance.h"

#include "SessionStartEvent.h"
#include "SessionEndEvent.h"
#include "FilePersistance.h"
#include "ServerPersistance.h"
#include "JsonSerializer.h"
#include <fstream>

Tracker* Tracker::instance = nullptr;


Tracker::Tracker(): gameID(), sessionID(), userID(), persistance(nullptr)
{
}

Tracker::~Tracker()
{
}

bool Tracker::Init(const std::string& storagePath, PersistanceType persistanceType, SerializerType serializerType)
{
    assert(instance == nullptr);

    instance = new Tracker();

    ISerializer* ser;

    switch (serializerType)
    {
    case Tracker::JSON_:
        ser = new JsonSerializer();
     /*   auto jser = static_cast<JsonSerializer*>(ser);
        if (jser != nullptr) jser->init();*/

        break;
    default:
        ser = new JsonSerializer();
        /*auto jser = static_cast<JsonSerializer*>(ser);
        if (jser != nullptr) jser->init();*/
        break;
    }

    char* buffer = new char[storagePath.length() + 1];
    strcpy_s(buffer, storagePath.length() + 1, storagePath.c_str());

    switch (persistanceType)
    {
    case Tracker::FilePersistance_:
        instance->persistance = new FilePersistance(ser, buffer);
        break;
    case Tracker::ServerPersistance_:
        instance->persistance = new ServerPersistance(ser, buffer);
        break;
    default:
        instance->persistance = new FilePersistance(ser, buffer);
        break;
    }

    return true;
}

void Tracker::setUserID(const uint16_t userNameID)
{
std::string line;

#if _WIN32
    std::string cmd = "getmac /nh";
    std::string filename = "macaddress.txt";

    system((cmd + ">" + filename).c_str());
    std::ifstream myfile("macaddress.txt");
    if (myfile.is_open()) {
        getline(myfile, line);
        getline(myfile, line);
        myfile.close();
    }
    remove("macaddress.txt");

    line = line.substr(0, 17);
    line.erase(remove(line.begin(), line.end(), '-'), line.end());

#endif

    userID = 0;

    for (int i = 0; i < line.length(); i += 2)
    {
        char c1 = line[i], c2 = line[i + 1];
        int intval1 = (c1 >= 'A') ? (c1 - 'A' + 10) : (c1 - '0');
        int intval2 = (c2 >= 'A') ? (c2 - 'A' + 10) : (c2 - '0');

        uint64_t byte = (intval1 << 4) | intval2;

        userID = userID | (byte << (4 * i) + 16);
    }

    userID = userID | userNameID;
}

void Tracker::setStoragePath(const std::string& path)
{
    char* buffer = new char[path.length()];
    strcpy_s(buffer, path.length(), path.c_str());

    persistance->setPath(buffer);
}

bool Tracker::Start()
{
    trackEvent<SessionStartEvent>();

    return true;
}

bool Tracker::End()
{
    trackEvent<SessionEndEvent>();

    persistance->flush();
    return true;
}

void Tracker::flush()
{
    persistance->flush();
}

//template<typename T, typename ...Targs>
//void Tracker::trackEvent(Targs&&... args)
//{
//    TrackerEvent* te = new T(std::forward<Targs>(args)...);
//
//    if (te != nullptr) {
//        te->setTimeStamp(getTimestamp());
//        te->setGameId(gameID);
//        te->setSessionId(sessionID);
//
//        //TODO: string OR unsigned long int
//        te->setUserId(userID);
//    }
//
//    persistance->send(te);
//}

time_t Tracker::getTimestamp()
{
    return time(nullptr);
}