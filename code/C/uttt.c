// programmed by fourfour
// to compile this use gcc as clang does not work "gcc uttt.c -o uttt"

#include <stdio.h>
#include <stdlib.h>

#define SUB_BOARD board[9]

char board[10][9] = { 
	{'.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.',},  // creating the board the correct size, the first 9 rows are the main board
	{'.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.',}  // this is the SUB_BOARD that is used for the end win of the game
};

void printBoard (int bold) {
	int i, j, k, l, m, n;
	printf("%c[H", 27);
	printf("%c[2J", 27);  //  clears the screen completely so that the UI will be the same, see note 2
	char printBorder [13] = {'|','|','-','-','-','|','|','-','-','-','|','|','/'}; // the border to get printed 
	char boldBorder [13] = {'I','I','=','=','=','I','I','=','=','=','I','I','/'}; // the bold options for all the borders
	int borderData [10][4] = {  // knows what borders are in effect for what square has been selected
		{0,2,13,13},
		{0,1,3,13},
		{1,4,13,13},
		{2,5,7,13},
		{3,5,6,8}, 
		{4,6,9,13},
		{7,10,13,13},
		{8,10,11,13},
		{9,11,13,13},
		{13,13,13,13},  // 13 here is used to send a nop
	};
	for ( i = 0; i < 4; i++ ) {  // used to replace all the borders with their bold counterparts
		printBorder[borderData[bold][i]] = boldBorder[borderData[bold][i]];
	}
	for ( i = 0; i < 3; i++ ) {
		for ( j = 0; j < 3; j++ ) {
			for ( k = 0; k < 3; k++ ) {
				for ( l = 0; l < 3; l++ ) {
				/* printf("%d %d \t", 3*i+k, 3*j+l);  used to print the places in the correct place, refer to note 1, this will produce the numbers as shown */
					printf(" %c", board[3*i+k][3*j+l]);
				}
				if ( k == 0 && i == 0 ) {
					printf(" %c", printBorder[0]);
				}
				if ( k == 1 && i == 0 ) {
					printf(" %c", printBorder[1]);
				}
				if ( k == 0 && i == 1 ) {
					printf(" %c", printBorder[5]); // this section prints the vertical borders with the correct bold variant
				}
				if ( k == 1 && i == 1 ) {
					printf(" %c", printBorder[6]);
				}
				if ( k == 0 && i == 2 ) {
					printf(" %c", printBorder[10]);
				}
				if ( k == 1 && i == 2 ) {
					printf(" %c", printBorder[11]);
				}
			}
			if ( i == 1 && j == 0 ) {
				printf("\t \t---+---+---");
			}
			if ( i == 1 && j == 1 ) {
				printf("\t \t %c | %c | %c", SUB_BOARD[3], SUB_BOARD[4], SUB_BOARD[5]); // this section prints the sub board that is used to win the game
			}
			if ( i == 1 && j == 2 ) {
				printf("\t \t---+---+---");
			}
			printf("\n");
		}
		if ( i == 0 ) {
			for ( m = 0; m < 3; m++ ) {
				for ( n = 0; n < 7; n++ ) {
					printf("%c", printBorder[2+m]); // this section and the one after print the correct horizontal bars
				}
				if ( m < 2 ) {
					printf("+");
				}
			}
		}
		if ( i == 1 ){
			for ( m = 0; m < 3; m++ ) {
				for ( n = 0; n < 7; n++ ) {
					printf("%c", printBorder[7+m]);
				}
				if ( m < 2 ) {
					printf("+");
				}
			}
		}
		if ( i < 2 ) {  /* used so that it does not print out a third time on the bottom */
			if ( i == 0 ) {
				printf("\t\t %c | %c | %c", SUB_BOARD[0], SUB_BOARD[1], SUB_BOARD[2]); // this section prints out the correct score on the sub board
			}
			if ( i == 1 ) {
				printf("\t\t %c | %c | %c", SUB_BOARD[6], SUB_BOARD[7], SUB_BOARD[8]);
			}

			printf("\n");
		}
	}
}

void printMessage ( const char message[] )
{
	printf("%c[H", 27);
	printf("%c[11B", 27);
	printf("%s", message);
	printf("%c[1B", 27);
	printf("%c[2K", 27);
	printf("%c[0J", 27);  // improves the UI and ensures that all incorrect inputs are cleared, see note 2
	printf("%c[1A", 27);
}

int validInput( int type, char player ) // checks all input to see if it is a valid number
{
	char valid [10] = {'1','2','3','4','5','6','7','8','9'};
	char input[2];
	int i, j;
	while ( 1 ) {  // different types for all the ways to select something
		if ( type == 0 ) {
			printMessage("Select the square to force to \n : ");
		}
		if ( type == 1 ) {
			printf("%c[k", 27);
			printf("\n\n %c : ", player);
		}
		// input = getchar();
		scanf("%s", input);
		for ( j = 0; j < 2; j++ ) {
			for ( i = 0; i < 9; i++ ) {
				if ( input[0] == valid[i] ) {
					return(input[0] - '0');  // the actual test part
				}
			}
		}
		printMessage("That is not a number");
	}
}

int checkWin ( int force, int player ) // goes throuth the board and will check if any one has won a square or the game
{
	int i;
	int win [8][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6}, // all the possible ways to win a square
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6},
	};
	for ( i = 0; i < 8; i++ ) {
		if ( board[force][win[i][0]] == board[force][win[i][1]] && board[force][win[i][1]] == board[force][win[i][2]] && board[force][win[i][1]] != '.' && SUB_BOARD[force] == '.' ) {  // checks the small squares
			SUB_BOARD[force] = player;
		}
	}

	for ( i = 0; i < 8; i++ ) {
		if ( SUB_BOARD[win[i][0]] == SUB_BOARD[win[i][1]] && SUB_BOARD[win[i][1]] == SUB_BOARD[win[i][2]] && SUB_BOARD[win[i][1]] != '.') {  // checks the main squares
			return(1);
		}
	}
	return(0);
}

void game ()
{
	printf("%c[2J", 27);
	int i;
	int j;
	int full;
	int tie = 1;
	int force;
	int input;
	int mainLoop = 1;
	char player = 'o';
	printBoard(9);
	input = validInput(0, player); 
	force = input - 1;
	while ( mainLoop == 1 ) {
		for ( i = 0; i < 9; i++ ) {
			for ( j = 0; j < 9; j++ ) {
				if ( board[i][j] ==  '.') {  // checks to see if the board is 100% full
					tie = 0;
				}
			}
		}
		if ( tie == 1 ) {
			printMessage("The game is a draw, you somehow managed to do that...");  // tie condition for the game
			input = getchar();
		}
		int validLoop = 0;
		if ( player == 'x' ) {  // swaps the players, could easily add more and the code would cope easily
			player = 'o';
		} else {
			player = 'x';
		}
		printBoard(input - 1);
		while ( validLoop == 0 ) {
			full = 1;
			for ( i = 0; i < 9; i++ ) {
				if ( board[force][i] == '.') {  // checks to see if the square you are in is full and if you need to force
					full = 0;
				}
			}
			if ( full == 1 ) {
				printBoard(9);
				input = validInput(0, player);  // allows the player to force and does the procedure
				force = input - 1;
				printBoard(input - 1);
			}
			input = validInput(1, player); 
			if ( board[force][input -1] != '.' ) {
				printMessage("That place is taken");
			} else {
				validLoop = 1;
			}
		}
		board[force][input - 1] = player;
		if ( checkWin(force, player) == 1 ) {  // runs the win check
			printMessage("The game is over, you win!");
			input = getchar();
			mainLoop = 0;
		}
		force = input - 1;
	}
	printBoard(9);
}

void reset ()
{
	int i, j;
	for ( i = 0; i < 10; i++ ) {
		for ( j = 0; j < 10; j++ ) {  // resets all boards to blank ( '.' )
			board[i][j] = '.';
		}
	}
}

int main ()
{
	int loop = 1;
	char input[100];
	while ( loop == 1 ) {
		printf("%c[2J", 27);
		printBoard(9);
//		printf("'s' to start a new game \t'q' to quit\n : ");  // the menu
		printMessage("'s' to start a new game \t'q' to quit\n : ");  // the menu
		reset();
		scanf("%s", input);
		if ( input[0] == 'q' ) {  // quits the game
			loop = 0;
		}
		if ( input[0] == 's' ) {  // runs the game
			game();
		}
	}
	return(0);
}








/*
 * common variables
board = the 9x9 array that holds the board and the pieces
SUB_BOARD = the 3x3 board that is actually used for the win of the game
i, j, k, l, m = loop variables used to draw the board correctly

 * functions
	main = the main menu that is used
		input:
			none
		return:
			'0' when the game is quit
		effects:
			actually makes the program run in the first place, runs game

	printBoard = used to print the board on the screen with the correct highlighting
		input:
			number - used to show what square to highlight, 0-8 are squares and 9 is for none
		return:
			none
		effects:
			prints the board and the borders for the board

	reset = cleans both the boards
		input:
			none
		return:
			none
		effects:
			resets the board so that everything is blank '.'

	game = runs the game loop
		input:
			none
		return:
			none
		effects:
			runs the logic for the game 
		
	checkWin = checks the boards to see if a player has won a square ( big and small ) or the game
		input:
			the current force square and the current player
		return:
			'1' if the game is over due to a win, '0' any other time
		effects:
			sets the SUB_BOARD to show a player when they win a square and returns '1' when the game is won

	validInput = checks the user input to clean it up and see if it is suitable
		input:
			type of input - normal move or force move
			player - so that it can print the player by the input
		return:
			the single char for the number that will be used ( first number in the input )
		effects:
			prints the input line and then reads it 

	printMessage
		input:
			a string that you want to print to the message line
		return:
			nothing
		effects:
			prints the provided string to the message line

 * NOTE 1 - the layout of the board and the rows / columns that the 4 board loop variables control
 
                  k                    k                    k
           l      l      l
	j	 [0][0] [0][1] [0][2] [1][0] [1][1] [1][2] [2][0] [2][1] [2][2]
		
i	j	 [0][3] [0][4] [0][5] [1][3] [1][4] [1][5] [2][3] [2][4] [2][5]
		
	j	 [0][6] [0][7] [0][8] [1][6] [1][7] [1][8] [2][6] [2][7] [2][8]
		
		
		 [3][0] [3][1] [3][2] [4][0] [4][1] [4][2] [5][0] [5][1] [5][2]
		
i		 [3][3] [3][4] [3][5] [4][3] [4][4] [4][5] [5][3] [5][4] [5][5]
		
		 [3][6] [3][7] [3][8] [4][6] [4][7] [4][8] [5][6] [5][7] [5][8]
		
		
		 [6][0] [6][1] [6][2] [7][0] [7][1] [7][2] [8][0] [8][1] [8][2]
		
i		 [6][3] [6][4] [6][5] [7][3] [7][4] [7][5] [8][3] [8][4] [8][5]
		
		 [6][6] [6][7] [6][8] [7][6] [7][7] [7][8] [8][6] [8][7] [8][8]

    
 * NOTE 2 - The layout on the screen will always follow the same layout no matter where you are (Game, Menu....so on)
 
 . . . | . . . | . . .                   \
 . . . | . . . | . . .                    |
 . . . | . . . | . . .                    |
-------+-------+-------		 . | . | .    |
 . . . | . . . | . . .	 	---+---+---   \
 . . . | . . . | . . .	 	 . | . | .     - 11 lines of board shown
 . . . | . . . | . . .	 	---+---+---   /
-------+-------+-------		 . | . | .    |
 . . . | . . . | . . .                    |
 . . . | . . . | . . .                    |
 . . . | . . . | . . .                   /

's' to start a new game 	'q' to quit  - 1 Message line

 :                                       - 1 input line
 
*/
