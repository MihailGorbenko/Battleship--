#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define SIZE 10                 //Size of battlefield
#define DEATH false           //State of ship
#define ALIVE true           //State of ship
#define HORISONT 1			//State of ship on the field
#define VERTICAL 0			//State of ship on the field
#define NO_ARG 1            //Output message about game status on the specified console point
#define PCSTAT_MSG 2		//Output message about game status on the specified console point
#define KILL_MSG 3			//Output message about game status on the specified console point
#define PLSTAT_MSG 4		//Output message about game status on the specified console point
#define ACT_MSG 5			//Output message about game status on the specified console point

typedef struct SHIP{        //One ship
	int deck_quantity;
	int live_deck;
	int locationY[4];
	int locationX[4];
	bool status;

}SHIP;

typedef struct FLEET{       //Fleet of ships
	SHIP fourDeckShip;
	SHIP threeDeckShip[2];
	SHIP twoDeckShip[3];
	SHIP oneDeckShip[4];
}FLEET;

/*This function takes as argument  battlefield and  Fleet of sheeps,
it  uses 'shipPlace()' function,and it automaticaly places ships on the battlefield.*/
void autoShipsPlacing(int field[][SIZE], FLEET *);

/*This function takes as argument player battlefield and player Fleet of ships ,
and it uses 'manualShipPlace();' 'displayField();' 'printGameStatus()' functions,
it rovides player manually place ships.*/
void playerShipsManualPlacing(int field[][SIZE], FLEET *);

/* This function takes as argument both battlefields and mode identifier,
if mode == 1 it displayes both fields, if mode == 0 it  displays only player battlefield.*/
void displayField(int PC_field[][SIZE], int player_field[][SIZE], int mode);

/*This function takes as argument battlefield, Fleet of ships, deck quantity of ship,
and ship id, to know in what ship to write coordinates, it do use 'collisionDetecrion()' - 
function to ensure that no one in coordinates that required.*/
void shipPlace(int deck_count, int field[][SIZE], FLEET *, int shipID);

/*This function takes as argument message string, and place identifier hat specifies 
in what console point print message.*/
void printGameStatus(char * message, int placeID);

/* This function takes as argument battlefield ,deck quantity of placing ship,direction placing ship,
and coordinates y & x of placing ship, and it  returns true if ship can be placed,and false if it can't. */
bool collisionDetection(int field[][SIZE], int deck_quantity, int direction, int y, int x);

/*This function is daughter for 'playerShipsManualPlacing()' and it returns true if ship succesfully placed, and false if was collision.*/
bool manualShipPlace(int deck_count, int field[][SIZE], FLEET*, int direction, int shipID, int fieldPoint[]);

/*This function takes as argument PC's battlefield and PC's Fleet of ships, and it provides user to make shot,
and check for hit by 'lookForHit()' function and it returns true if HIT, false if MISS, or print that coordinates alredy token
if they are.*/
bool getPlayerShot(int PCfield[][SIZE], FLEET * PCships);

/*This function takes as argument player's battlefield,player's Fleet of ships, and identifier 'shotByShot',
that specifies what attempt was made by one time,if it was  first attempt it generate coordinates by random,
but if it was second attempt it tryes to guess direction of next shot,but if it's hited two or three times by one  time,
it makes shot in previous direction but in next point.It returns true if HIT and false if MISS.*/
bool getPCshot(int playerFied[][SIZE], FLEET * PlayerShips, int shotByShot);

/*This function takes as argument both of Fleets,and it cheks all ship's status,
and it count down ships that dead and it returns false if game is over and print who is winner.*/
bool gameMonitor(FLEET * playerShips, FLEET * PCships);

/* This function takes battlefield in what to look,Fleet on this field,and coordinates of shot,
it returnes -1 if this point already  hited or MISS,returns 1 if HIT. */
int lookForHit(int field[][SIZE], FLEET * ships, int y, int x);

/*This function turns player's entered symbol in it's index equivalent of matrix.*/
int turnInInt(char symb);