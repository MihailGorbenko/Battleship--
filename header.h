#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define Y 10
#define X 10
#define DEATH false
#define ALIVE true
#define HORISONT 1
#define VERTICAL 0

typedef struct SHIP{
	int deck_quantity;
	int live_deck;
	int locationY[4];
	int locationX[4];
	bool status;

}SHIP;

typedef struct FLEET{
	SHIP fourDeckShip;
	SHIP threeDeckShip[2];
	SHIP twoDeckShip[3];
	SHIP oneDeckShip[4];
}FLEET;

void playerShipsAutoPlacing(int field[][SIZE],FLEET *);

void PCshipsPlacing(int field[][SIZE], FLEET *);

void playerShipsHandlePlacing(int field[][SIZE],FLEET *,int PCfield[][SIZE]);

void displayPole(int PC_field[][SIZE],int player_field[][SIZE],int mode);

void shipPlace(int deck_count, int field[][SIZE], FLEET *, int shipID);

bool collisionDetection(int field[][SIZE], int deck_quantity, int direction, int y, int x);

bool handleShipPlace(int deck_count,int field[][SIZE], FLEET*, int direction,int shipID);

int turnInInt(char symb);

bool getPlayerShot(int PCfield[][SIZE], FLEET * PCships);

bool getPCshot(int playerFied[][SIZE], FLEET * PlayerShips);

int lookForHit(int field[][SIZE], FLEET * ships,int y,int x);

int gameMonitor(FLEET * playerShips,FLEET * PCships);

