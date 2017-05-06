
#include "header.h"


//*************************************
bool getPlayerShot(int PCfield[][SIZE], FLEET * PCships){
	int y = 0;
	char x = '\0';
	printGameStatus("Make your shot                                                                        ", ACT_MSG);
	printGameStatus("Enter Y coordinates:(1-10)                                                              >>",NO_ARG);
	while (true){
		if (scanf("%d", &y) == 0) printGameStatus(" Not valid choise! Enter again(1-10)                      ", PLSTAT_MSG);
		if (y > 10 || y< 1){
			printGameStatus(" Not valid choise! Enter again(1-10)                                          >> ", PLSTAT_MSG);
		}
		else break;
		while (getchar() != '\n')continue;
	}
	printGameStatus("Enter X coordinates:(A-J - In upper case)                                                  >>", NO_ARG);
	while (getchar() != '\n')continue;
	while (true){
		if (scanf("%c", &x) == 0)printGameStatus(" Not valid choise! Enter again(A-J - In upper case)           ", PLSTAT_MSG);
		if ((int)x < 65 || (int)x > 74){
			printGameStatus("Not valid choise! Enter again(A-J - In upper case)                                 ", PLSTAT_MSG);
		}
		else break;
		while (getchar() != '\n')continue;
	}
	if (lookForHit(PCfield, PCships, (y - 1), turnInInt(x)) == 1) {
		printGameStatus("You are HIT                                                                             ", PLSTAT_MSG);
		PCfield[y - 1][turnInInt(x)] = 100;
		
	}
	else if (lookForHit(PCfield, PCships, (y - 1), turnInInt(x)) == 0){
		printGameStatus("You are MISS                                                                             ", PLSTAT_MSG);
		PCfield[y - 1][turnInInt(x)] = 5;
		
		return false;
	}

	else printGameStatus("This coordinates alredy token                                                            ", PLSTAT_MSG);

	return  true;
}
//*******************************
int gameMonitor(FLEET * playerShips, FLEET * PCships){
	int  playerShipsAlive = 10;
	int PCshipsAlive = 10;
	// check for player ships
	if (playerShips->fourDeckShip.status == DEATH)
		playerShipsAlive--;
	for (int i = 0; i < 2; i++)
	{
		if (playerShips->threeDeckShip[i].status == DEATH)
			playerShipsAlive--;
	}
	for (int i = 0; i < 3; i++){
		if (playerShips->twoDeckShip[i].status == DEATH)
			playerShipsAlive--;
	}
	for (int i = 0; i < 4; i++){
		if (playerShips->oneDeckShip[i].status == DEATH)
			playerShipsAlive--;
	}
	//check for PC ships
	if (PCships->fourDeckShip.status == DEATH)
		PCshipsAlive--;
	for (int i = 0; i < 2; i++){
		if (PCships->threeDeckShip[i].status == DEATH)
			PCshipsAlive--;
	}
	for (int i = 0; i < 3; i++){
		if (PCships->twoDeckShip[i].status == DEATH)
			PCshipsAlive--;
	}
	for (int i = 0; i < 4; i++){
		if (PCships->oneDeckShip[i].status == DEATH)
			PCshipsAlive--;
	}
	//checking for end and winner
	if (playerShipsAlive == 0 && PCshipsAlive == 0){
		printGameStatus("NOBODY WINS                                              ", PCSTAT_MSG);
		return false;
	}
	
	if (PCshipsAlive == 0 && playerShipsAlive > 0){
		printGameStatus("Player WINS!!!                                           ",PLSTAT_MSG);
		return false;
	}
	 if (playerShipsAlive == 0 && PCshipsAlive > 0) {
		printGameStatus("PC WINS!!!                                              ", PCSTAT_MSG);
		return false;
	}
	 return true;
}

//******************************
bool getPCshot(int playerField[][SIZE], FLEET * PlayerShips, int shotByShot){
	static int Y_PC_SHOT = 0;
	static int X_PC_SHOT = 0;
	static int guessDirection = 0;
	printGameStatus("PC makes shot!                                ",ACT_MSG);
	while (true){
		if (shotByShot == 0){                  //if first hit
			Y_PC_SHOT = rand() % 10;
			X_PC_SHOT = rand() % 10;
		}
		else if(shotByShot == 1){                //if second hit by one time
			guessDirection = (rand() % 4) + 1;
			switch (guessDirection)
			{
			case 1:   //top
			{
				if (Y_PC_SHOT > 0)
				       Y_PC_SHOT--;
				else{
					Y_PC_SHOT = rand() % 10;
					X_PC_SHOT = rand() % 10;
					continue;
				}

				break;
			}
			case 2:  //right
			{
				if (X_PC_SHOT <9)
				       X_PC_SHOT++;
				else{
					Y_PC_SHOT = rand() % 10;
					X_PC_SHOT = rand() % 10;
					continue;
				}
				break;
			}
			case 3:   //down
			{
				if (Y_PC_SHOT < 9)
				        Y_PC_SHOT++;
				else {
					Y_PC_SHOT = rand() % 10;
					X_PC_SHOT = rand() % 10;
					continue;
				}
				break;
			}
			case 4:   //  left
			{
				if (X_PC_SHOT >0)
				        X_PC_SHOT--;
				else {
					Y_PC_SHOT = rand() % 10;
					X_PC_SHOT = rand() % 10;
					continue;
				}
				break;
			}
			}
		}
		else                 //if third and fourth hit by one time
		{
			switch (guessDirection)
			{
			case 1:   //top
			{
				if (Y_PC_SHOT > 0)
					Y_PC_SHOT--;
				else {
					Y_PC_SHOT = rand() % 10;
					X_PC_SHOT = rand() % 10;
					continue;
				}
				break;
			}
			case 2:  //right
			{
				if (X_PC_SHOT <9)
					X_PC_SHOT++;
				else{
					Y_PC_SHOT = rand() % 10;
					X_PC_SHOT = rand() % 10;
					continue;
				}
				break;
			}
			case 3:   //down
			{
				if (Y_PC_SHOT < 9)
					Y_PC_SHOT++;
				else{
					Y_PC_SHOT = rand() % 10;
					X_PC_SHOT = rand() % 10;
					continue;
				}
				break;
			}
			case 4:   //  left
			{
				if (X_PC_SHOT >0)
					X_PC_SHOT--;
				else {
					Y_PC_SHOT = rand() % 10;
					X_PC_SHOT = rand() % 10;
					continue;
				}
				break;
			}
			}
		}

		if (lookForHit(playerField, PlayerShips, Y_PC_SHOT, X_PC_SHOT) == 1){
			playerField[Y_PC_SHOT][X_PC_SHOT] = 100;
			printGameStatus("PC HIT!                                  ",PCSTAT_MSG);

			break;
		}
		else if (lookForHit(playerField, PlayerShips, Y_PC_SHOT, X_PC_SHOT) == 0){
			playerField[Y_PC_SHOT][X_PC_SHOT] = 5;
			printGameStatus("PC MISS!                                 ", PCSTAT_MSG);
			return false;
		}
		else continue;
	}
	return true;
}
//****************
int lookForHit(int field[][SIZE], FLEET * fleet, int y, int x){
	
	if (field[y][x] == 100) {                     //already hited
		return -1;
	}
	else if (field[y][x] == 4){     //hit four-deck ship
		fleet->fourDeckShip.live_deck--;
		if (fleet->fourDeckShip.live_deck <= 0){
			fleet->fourDeckShip.status = DEATH;
			printGameStatus("Four - deck ship death!             ",KILL_MSG);
		}

		return 1;
	}
	else if (field[y][x] == 3){
		//hit 3 - deck ship
		for (int i = 0; i < 2; i++){
			int  got = 0;
			for (int j = 0; j < 4; j++){
				if (fleet->threeDeckShip[i].locationY[j] == y){
					got++;
				}
			}
			for (int j = 0; j < 4; j++){
				if (fleet->threeDeckShip[i].locationX[j] == x){
					got++;
				}
			}
			if (got == 2){
				fleet->threeDeckShip[i].live_deck--;
				if (fleet->threeDeckShip[i].live_deck <= 0){
					fleet->threeDeckShip[i].status = DEATH;
					printGameStatus("Three - deck ship death!              ",KILL_MSG);
				}

			}
			else continue;
		}
		return 1;
	}
	else if (field[y][x] == 2){      //hit 2 - deck ship

		for (int i = 0; i < 3; i++){
			int  got = 0;
			for (int j = 0; j < 4; j++){
				if (fleet->twoDeckShip[i].locationY[j] == y){
					got++;
				}
			}
			for (int j = 0; j < 4; j++){
				if (fleet->twoDeckShip[i].locationX[j] == x){
					got++;
				}
			}
			if (got == 2){
				fleet->twoDeckShip[i].live_deck--;
				if (fleet->twoDeckShip[i].live_deck <= 0){
					fleet->twoDeckShip[i].status = DEATH;
					printGameStatus("TWO-deck ship death!                 ",KILL_MSG);
				}
			}
			else continue;
		}
		return 1;
	}
	else if (field[y][x] == 1){      //hit 1 - deck ship

		for (int i = 0; i < 4; i++){
			int  got = 0;
			for (int j = 0; j < 4; j++){
				if (fleet->oneDeckShip[i].locationY[j] == y){
					got++;
				}
			}
			for (int j = 0; j < 4; j++){
				if (fleet->oneDeckShip[i].locationX[j] == x){
					got++;
				}
			}
			if (got == 2){
				fleet->oneDeckShip[i].live_deck--;
				if (fleet->oneDeckShip[i].live_deck <= 0){
					fleet->oneDeckShip[i].status = DEATH;
					printGameStatus("One deck ship death!               ",KILL_MSG);
				}
			}
			else continue;
		}
		return true;
	}
	else if (field[y][x] == 5){
		return -1;
	}

	else return 0;
}
