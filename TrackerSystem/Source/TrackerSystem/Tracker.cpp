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

bool Tracker::Init(const std::string& storageDir, PersistanceType persistanceType, SerializerType serializerType, int nEventsToFlush)
{
    assert(instance == nullptr);

    //Inicializa la instancia
    instance = new Tracker();
    
    //Obtención del numero de sesion del fichero
    FILE* file;
    std::ifstream f("sesion.txt");
    if (f.good()) { //Si ya existe el fichero
        f.close();
        fopen_s(&file, "sesion.txt", "r+");
        fread(&instance->sessionID, sizeof(int), 1, file);
        instance->sessionID++; //la sesión es la siguiente a la ultima
    }
    else { //Si no existe el fichero
        f.close();
        //Se crea el fichero
        fopen_s(&file, "sesion.txt", "a");
        fclose(file);
        fopen_s(&file, "sesion.txt", "r+");
        instance->sessionID = 0; //la sesión es la primera
    }
    rewind(file);
    //Se escribe la nueva sesion en el fichero
    fwrite(&instance->sessionID, sizeof(int), 1, file);
    fclose(file);

    instance->maxEventsToFlush = nEventsToFlush;
    instance->nEventsWithoutFlush = 0;

    //Se crea el serializador del tipo especificado
    ISerializer* ser;
    switch (serializerType)
    {
    case Tracker::JSON_:
        ser = new JsonSerializer();
        break;
    default:
        ser = new JsonSerializer();
        break;
    }

    //Se crea  el persistance del tipo especificado
    switch (persistanceType)
    {
    case Tracker::FilePersistance_: {
            std::string path = storageDir + "sesion" + std::to_string(instance->sessionID);
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
    default: { //En el caso por defecto se usa file persistance
            std::string path = storageDir + "sesion" + std::to_string(instance->sessionID);
            char* buff = new char[path.length() + 1];
            strcpy_s(buff, path.size() + 1, path.c_str());
            instance->persistance = new FilePersistance(ser, buff);
            break;
        }
    }

    return true;
}

void Tracker::setUserID()
{
    //Obtencion de la direccion MAC del usuario
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

    //Se copia la direccion a un entero sin signo
    for (int i = 0; i < line.length(); i += 2)
    {
        char c1 = line[i], c2 = line[i + 1];
        int intval1 = (c1 >= 'A') ? (c1 - 'A' + 10) : (c1 - '0');
        int intval2 = (c2 >= 'A') ? (c2 - 'A' + 10) : (c2 - '0');

        uint64_t byte = (intval1 << 4) | intval2;

        userID = userID | (byte << (4 * i) + 16);
    }

    //Se combina el id del ususario recibido con la direccion MAC
    userID = userID;
}

void Tracker::setStoragePath(const std::string& path)
{
    char* buffer = new char[path.length()];
    strcpy_s(buffer, path.length(), path.c_str());

    persistance->setPath(buffer);
}

void Tracker::Start()
{
    setUserID();
    trackEvent(new SessionStartEvent());
}

void Tracker::End()
{
    trackEvent(new SessionEndEvent());
    persistance->flush();
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
    nEventsWithoutFlush++;
    if (nEventsWithoutFlush >= maxEventsToFlush) {
        flush();
        nEventsWithoutFlush = 0;
    }
}

time_t Tracker::getTimestamp()
{
    return time(nullptr);
}