#include "Tracker.h"
#include "UtensilBecomesDirtyEvent.h"
#include "DishFinishedEvent.h"
#include "IngredientKillEvent.h"

#include <chrono>
#include <thread>

int main(int argc, char *argv[]) {

	Tracker::Init();

	auto a = Tracker::Instance();

	a->setUserID(1);

	a->Start();

	a->trackEvent(new UtensilBecomesDirtyEvent());
	a->trackEvent(new DishFinishedEvent());

	//REVISAR ESTO CON LA FORMA DE MANDAR EVENTOS
	a->trackEvent(new IngredientKillEvent()); // Escribe bien en json

	IngredientKillEvent* ingKill = new IngredientKillEvent();	//No escribe bien en json
	ingKill->setLevelId(0);
	ingKill->setMistake(true);
	a->trackEvent(ingKill);

	a->End();

	delete a;
	//while(true){}

	return 0;
}   