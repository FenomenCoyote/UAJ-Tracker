#include "pch.h"
#include "Tracker.h"
#include "TrackerEvent.h"
#include "IPersistance.h"

#include "SessionStartEvent.h"
#include "SessionEndEvent.h"


Tracker* Tracker::instance = nullptr;


Tracker::Tracker(): gameID(), sessionID()
{

}

Tracker::~Tracker()
{
}


bool Tracker::Init()
{
    instance = new Tracker();

    return true;
}

void Tracker::setUserID(const std::string& userNameID)
{
    /*
        
    string cmd = "getmac";
    string filename = "macaddress.txt";

    system((cmd + ">" + filename).c_str());
    string line;
    ifstream myfile("macaddress.txt");

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << line << endl;
        }
        myfile.close();
    }
    else
        cout << "Unable to open the file";
    
    */

    userID = userNameID;
}

void Tracker::setStoragePath(const std::string& path)
{
    this->path = path;
}

bool Tracker::Start()
{
    trackEvent<SessionStartEvent>();

    return true;
}

bool Tracker::End()
{
    trackEvent<SessionEndEvent>();

    return true;
}

std::time_t Tracker::getTimestamp()
{
    return std::time(nullptr);
}