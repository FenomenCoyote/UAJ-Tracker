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
	delete persistance;
}

bool Tracker::Init(const std::string& storagePath, PersistanceType persistanceType, SerializerType serializerType)
{
    assert(instance == nullptr);

    instance = new Tracker();

    FILE* file;
    std::ifstream f("sesion.txt");

    if (f.good()) {
        f.close();
        fopen_s(&file, "sesion.txt", "r+");
        fread(&instance->sessionID, sizeof(int), 1, file);
        instance->sessionID++;
    }
    else {
        f.close();
        fopen_s(&file, "sesion.txt", "a");
        fclose(file);
        fopen_s(&file, "sesion.txt", "r+");
    }
    rewind(file);
    fwrite(&instance->sessionID, sizeof(int), 1, file);
    fclose(file);

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

    switch (persistanceType)
    {
    case Tracker::FilePersistance_: {

            std::string path = storagePath + "sesion" + std::to_string(instance->sessionID);
            char* buff = new char[path.length() + 1];
            strcpy_s(buff, path.size() + 1, path.c_str());
            instance->persistance = new FilePersistance(ser, buff);

            break;
        }
    case Tracker::ServerPersistance_:{
            std::string path = "server";
            char* buff = nullptr;
            strcpy_s(buff, path.size(), path.c_str());
            instance->persistance = new ServerPersistance(ser, buff);
            break;
        }
    default: {

            std::string path = storagePath + "sesion" + std::to_string(instance->sessionID);
            char* buff = new char[path.length() + 1];
            strcpy_s(buff, path.size() + 1, path.c_str());
            instance->persistance = new FilePersistance(ser, buff);

            break;
        }
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
    

    trackEvent(new SessionStartEvent());

    return true;
}

bool Tracker::End()
{
    trackEvent(new SessionEndEvent());

    persistance->flush();
	
    return true;
}

void Tracker::flush()
{
    persistance->flush();
}

void Tracker::trackEvent(TrackerEvent* e)
{
	e->setTimeStamp(getTimestamp());
	e->setGameId(gameID);
	e->setSessionId(sessionID); 
	e->setUserId(userID);
	persistance->send(e);
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