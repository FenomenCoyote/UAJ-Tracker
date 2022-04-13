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

	a->trackEvent<UtensilBecomesDirtyEvent>();
	a->trackEvent<DishFinishedEvent>();

	//REVISAR ESTO CON LA FORMA DE MANDAR EVENTOS
	a->trackEvent<IngredientKillEvent>(); // Escribe bien en json

	IngredientKillEvent ingKill;	//No escribe bien en json
	ingKill.setItemId(0);
	ingKill.setMistake(true);
	a->trackEvent(ingKill);

	a->End();

	while(true){}

	return 0;
}   