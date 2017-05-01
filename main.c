#include "header.h"

int main(){
	srand(time(NULL));
	bool autoPlacing = false;
	int choise = -1;
	// FIELDS  (100 -- HIT; | 1,2,3,4 -- SHIPS; | 0 -- SEA;)
	int player_field[Y][X] = { 0 };
	int PC_field[Y][X] = { 0 };
	//************************
	FLEET * playerShips, * PCships;
	FLEET ps, pcs;
	playerShips = &ps; //player fleet
	PCships = &pcs; //PC fleet
	//************************
    // ships initialization
	FLEET * allFlets[2] = { playerShips, PCships };
	for (int i = 0; i < 2; i++){
		allFlets[i]->fourDeckShip.deck_quantity = 4;
		allFlets[i]->fourDeckShip.live_deck = 4;
		allFlets[i]->fourDeckShip.status = ALIVE;
		for (int t = 0; t < 4; t++){
			allFlets[i]->fourDeckShip.locationY[t] = -1;
			allFlets[i]->fourDeckShip.locationX[t] = -1;
		}
		for (int j = 0; j < 2; j++){
			allFlets[i]->threeDeckShip[j].deck_quantity = 3;
			allFlets[i]->threeDeckShip[j].live_deck = 3;
			allFlets[i]->threeDeckShip[j].status = ALIVE;
			for (int t = 0; t < 4; t++){
				allFlets[i]->threeDeckShip[j].locationY[t] = -1;
				allFlets[i]->threeDeckShip[j].locationX[t] = -1;
			}
		}
		for (int k = 0; k < 3; k++){
			allFlets[i]->twoDeckShip[k].deck_quantity = 2;
			allFlets[i]->twoDeckShip[k].live_deck = 2;
			allFlets[i]->twoDeckShip[k].status = ALIVE;
			for (int t = 0; t < 4; t++){
				allFlets[i]->twoDeckShip[k].locationY[t] = -1;
				allFlets[i]->twoDeckShip[k].locationX[t] = -1;
			}
		}
		for (int n = 0; n < 4; n++){
			allFlets[i]->oneDeckShip[n].deck_quantity = 1;
			allFlets[i]->oneDeckShip[n].live_deck = 1;
			allFlets[i]->oneDeckShip[n].status = ALIVE;
			for (int t = 0; t < 4; t++){
				allFlets[i]->oneDeckShip[n].locationY[t] = -1;
				allFlets[i]->oneDeckShip[n].locationX[t] = -1;
			}
		}
	}
	puts("_____________________________________________________________________________");
	puts("___________________________WELCOME TO BATTLESHIP_____________________________");
	puts("_____________________________________________________________________________");
	puts("Chose the way to place your ships:\n\t$>1-automatically;\n\t$>0-handle;\n");
	//choosing  ship placing type;
	while (true){
		scanf("%d", &choise);
		if (choise > 1 || choise < 0){
			puts("$> Not valid choise!\n$> Enter again ");
		}
		else break;
		while (getchar() != '\n')continue;
	} 
	if (choise == 1) autoPlacing = true;
	//************************************

	switch (autoPlacing){
	case true:
	{ 
		
		
		playerShipsAutoPlacing(player_field, playerShips);
		PCshipsPlacing(PC_field, PCships);
		displayPole(PC_field, player_field, 1);
		while (gameMonitor(playerShips, PCships)){
			int shotByShot = 0;                    // if > than one to try to guess next deck of this ship
			while (getPlayerShot(PC_field, PCships)){
				displayPole(PC_field, player_field, 1);
			}
			while (getPCshot(player_field, playerShips,shotByShot)){
				displayPole(PC_field, player_field, 1);
				shotByShot++;
			}	
			displayPole(PC_field, player_field, 1);
		}
		break;
	}
	case false:
	{
		playerShipsHandlePlacing(player_field,playerShips,PC_field);
		PCshipsPlacing(PC_field,PCships);
		puts("Let's go!\n");
		displayPole(PC_field, player_field,1);
		while (gameMonitor( playerShips, PCships)){
			int shotByShot = 0;
			while (getPlayerShot(PC_field, PCships)){
				displayPole(PC_field, player_field, 1);
			}
			while (getPCshot(player_field, playerShips,shotByShot)){
				displayPole(PC_field, player_field, 1);
				shotByShot++;
			}
			displayPole(PC_field, player_field, 1);
		} 
		break;
	  }
	}
	return 0;
}