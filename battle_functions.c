#include "header.h"

int Y_PC_SHOT;
int X_PC_SHOT;
//*************************************
bool getPlayerShot(int PCfield[][SIZE], FLEET * PCships){
	int y = 0;
	char x = '\0';
	puts("\nMake your shot:\n");
	printf("Enter Y coordinates:(1-10)\n$>");
	while (true){
		if (scanf("%d", &y) == 0)puts("\n$> Not valid choise!\n$> Enter again ");
		if (y > 10 || y< 1){
			puts("\n$> Not valid choise!\n$> Enter again ");
		}
		else break;
		while (getchar() != '\n')continue;
	}
	printf("Enter X coordinates:(A-J - In upper case)\n$>");
	while (getchar() != '\n')continue;
	while (true){
		if (scanf("%c", &x) == 0)puts("\n$> Not valid choise!\n$> Enter again ");
		if ((int)x < 65 || (int)x > 74){
			puts("\n$> Not valid choise!\n$> Enter again ");
		}
		else break;
		while (getchar() != '\n')continue;
	}
	if (lookForHit(PCfield, PCships, (y - 1), turnInInt(x))==1) {
		printf("\nYou are hit\n");
		PCfield[y - 1][turnInInt(x)] = 100;
	}
	else if (lookForHit(PCfield, PCships, (y - 1), turnInInt(x)) == 0){
		puts("\nMISS\n");
		PCfield[y - 1][turnInInt(x)] = 5;
		return false;
	}
	
	else puts("\nThis coordinates alredy token\n");
		
	return  true;
}
//*******************************
int gameMonitor( FLEET * playerShips, FLEET * PCships){
	int shots;
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
	if (playerShipsAlive == 0 && PCshipsAlive > 0) {
		printf("\nPC WINS!!!\n");
		return false;
	}
	else if (playerShipsAlive > 0 && PCshipsAlive == 0){
		printf("\nPlayer WINS!!!\n");
		return false;
	}
	else if (playerShipsAlive == 0 && PCshipsAlive == 0){
		printf("\nNOBODY WINS\n ");
		return false;
	}
	else return true;
}

//******************************
bool getPCshot(int playerField[][SIZE], FLEET * PlayerShips,int shotByShot){ 
	int guessDirection = 0;
	puts("PC makes shot!");
	while (true){
		if (shotByShot < 1){
			Y_PC_SHOT = rand() % 10;
			X_PC_SHOT = rand() % 10;
		}
		else{
			guessDirection = (rand() % 4) + 1;
			switch (guessDirection)
			{
			case 1:   //top 
			{
				Y_PC_SHOT--;
				break;
			}
			case 2:  //right
			{
				X_PC_SHOT++;
				break;
			}
			case 3:   //down
			{
				Y_PC_SHOT++;
				break;
			}
			case 4:   //  left
			{
				X_PC_SHOT--;
				break;
			}
			}
		}
	
		if (lookForHit(playerField, PlayerShips, Y_PC_SHOT, X_PC_SHOT) == 1){
			playerField[Y_PC_SHOT][X_PC_SHOT] =100;
			puts("PC HIT!\n");
			break;
		}
		else if (lookForHit(playerField, PlayerShips, Y_PC_SHOT, X_PC_SHOT) == 0){
			playerField[Y_PC_SHOT][X_PC_SHOT] = 5;
			puts("PC MISS!\n");
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
			printf("\nFour - deck ship death!\n");
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
					printf("\nThree - deck ship death!\n");
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
					printf(" \nTWO-deck ship death!\n");
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
					printf("\nOne deck ship death!\n");
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