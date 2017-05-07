#include "header.h"

void printGameStatus(char * message, int placeID)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position_YX = { 4, 20 };

	SetConsoleCursorPosition(Console, Position_YX);
	if (placeID == NO_ARG)
	{
		SetConsoleTextAttribute(Console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf(message, placeID);
		SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	else if (placeID == ACT_MSG){
		Position_YX.Y--;
		SetConsoleCursorPosition(Console, Position_YX);
		SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf(message);
		SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	else if (placeID == PLSTAT_MSG){
		Position_YX.Y += 3;
		SetConsoleCursorPosition(Console, Position_YX);
		SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf(message);
		SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	else if (placeID == PCSTAT_MSG){
		Position_YX.Y += 4;
		SetConsoleCursorPosition(Console, Position_YX);
		SetConsoleTextAttribute(Console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf(message);
		SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	else if (placeID == KILL_MSG){
		Position_YX.Y += 5;
		SetConsoleCursorPosition(Console, Position_YX);
		printf(message);
	}
	else
		printf(message);

}
//--------------------------------------------------------------------------

void displayField(int PC_field[][SIZE], int player_field[][SIZE], int mode){
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("\n%s", "  ABCDEFGHIJ");
	if (mode == 1){
		printf("\t\t\t\t");
		printf("%s\n", "  ABCDEFGHIJ");
	}
	else
	{
		putchar('\n');
	}
	for (int i = 0; i < SIZE; i++){

		//*******player field**************
		(i == 9 ? printf("%d", (i + 1)) : printf("%d ", (i + 1)));

		for (int j = 0; j < SIZE; j++){
			if (player_field[i][j] == 0){
				SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("%c", (char)176);   //SEA
				SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			else if (player_field[i][j] == 1 || player_field[i][j] == 2 || player_field[i][j] == 3 || player_field[i][j] == 4){
				SetConsoleTextAttribute(Console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("%c", 'S');  //SHIP
				SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			else if (player_field[i][j] == 5){
				SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("%c", 'O');  // MISS
				SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			else if (player_field[i][j] == 100){
				SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("%c", 'X');    //HIT
				SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
		}
		if (mode == 1){
			//***********PC FIELD***************
			printf("\t\t\t\t");
			(i == 9 ? printf("%d", (i + 1)) : printf("%d ", (i + 1)));
			for (int j = 0; j < SIZE; j++){
				if (PC_field[i][j] == 100){
					SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
					printf("%c", 'X');  //HIT
					SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				}
				else if (PC_field[i][j] == 5){
					SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					printf("%c", 'O');  //MISS
					SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				}

				/* else if (PC_field[i][j] == 1 || PC_field[i][j] == 2 || PC_field[i][j] == 3 || PC_field[i][j] == 4){
				SetConsoleTextAttribute(Console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("%c", 'S');  //SHIP
				SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				} */
				// UNCOMENT TO SEE PC SHIPS <--------------<------<<---------|

				else  {
					SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					printf("%c", (char)176);// SEA
					SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				}
			}
			//**************************
		}

		printf("\n");
	}
	printf("\n\n");
}