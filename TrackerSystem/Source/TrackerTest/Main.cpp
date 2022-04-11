#include "Tracker.h"

#include <chrono>
#include <thread>

int main(int argc, char *argv[]) {

	Tracker::Init();

	auto a = Tracker::Instance();

	a->setUserID(1);

	a->Start();

	a->End();

	return 0;
}   