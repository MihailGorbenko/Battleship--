
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define SIZE 10
#define _Y_ 10
#define _X_ 10
#define DEATH false
#define ALIVE true
#define HORISONT 1
#define VERTICAL 0
#define NO_ARG 1
#define PLSTAT_MSG 4
#define KILL_MSG 3
#define PCSTAT_MSG 2
#define ACT_MSG 5
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

void playerShipsAutoPlacing(int field[][SIZE], FLEET *);

void PCshipsPlacing(int field[][SIZE], FLEET *);

void playerShipsHandlePlacing(int field[][SIZE], FLEET *, int PCfield[][SIZE]);

void displayPole(int PC_field[][SIZE], int player_field[][SIZE], int mode);

void shipPlace(int deck_count, int field[][SIZE], FLEET *, int shipID);

void printGameStatus(char * message, int dig);

bool collisionDetection(int field[][SIZE], int deck_quantity, int direction, int y, int x);

bool handleShipPlace(int deck_count, int field[][SIZE], FLEET*, int direction, int shipID);

bool getPlayerShot(int PCfield[][SIZE], FLEET * PCships);

bool getPCshot(int playerFied[][SIZE], FLEET * PlayerShips, int shotByShot);

int lookForHit(int field[][SIZE], FLEET * ships, int y, int x);

int gameMonitor(FLEET * playerShips, FLEET * PCships);

int turnInInt(char symb);