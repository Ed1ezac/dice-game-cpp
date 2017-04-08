/*
*CREATED BY: E. KEALEBOGA
*
*/
#include<iostream>
using namespace std;

int turnScore = 0;/////The score for each game turn
int totalScoreA = 0;////Total score for player 1
int totalScoreB = 0;////Total score for player 2

////The following function checks how much was rolled by the dice, three parameters, the dice and respective gameturns
//returns nothing
void checkRoll(int die, int playerATurn, int playerBTurn) {
	int sixTurn = 0;//////This integer serves as control for turns played when a player rolls a six
    char rollAgain = 'r' ;////input character to roll again

beginCheck ://////goto label to check if player has rolled a six again

	/////////////if selection, to check if a player rolled a six
	if (die == 6) {
		
		////Checks if playerA's turn is currently active and if its not the third time they roll
			if ((playerATurn == 1) && !(sixTurn == 2)) {
				cout << "You rolled a SIX, roll again!!\n";////prompts player to play again
				++sixTurn;////increments sixTurn variable
				turnScore = die;////takes die and puts it in turnScore
				totalScoreA += turnScore;////increments totalScore by turnScore
				cout << "Total score: " << totalScoreA << endl;//shows current score

				cin >> rollAgain;////listens for rollagain input
				die = 1 + (rand() % 6); /////////////////rolls a Die

				goto beginCheck;////returns program to label to check if die is six

			}
			////Simillar to above selection statement but for playerB
			else if ((playerBTurn == 1) && !(sixTurn == 2))
			{
				cout << "You rolled a SIX, roll again!!\n";
				++sixTurn;
				turnScore = die;
				totalScoreB += turnScore;
				cout << "Total score: " << totalScoreB << endl;

				cin >> rollAgain;
				die = 1 + (rand() % 6); /////////////////rolls a Die

				goto beginCheck;

			}//ends else if

			//Checks if Either player (PlayerA or PlayerB) is rolling for the third time and skips their turn
			//sixTurn==2 is first condition here because its almost always false, hence quicker code
			else if ((sixTurn == 2) && ((playerBTurn == 1) || (playerATurn == 1)))
			{
				cout << "Now you're cheating!\n\n\n\n";
			}//ends else if

	}//ends if

	/////Alternatives to die = 6 selection statement above, for both players
	else if ((playerATurn == 1) && !(die == 6))
	{
		cout << "You rolled a: " << die;
		turnScore = die;/////Increments turnscore by die
		totalScoreA += turnScore;////Increments playerA's total score by turnscore
		cout << " Your Total Score is: " << totalScoreA << "\n\n\n\n" << endl;//shows player's score
	}//ends else if
	else if ((playerBTurn == 1) && (die != 6))
	{
		cout << "You rolled a: " << die;
		turnScore = die;
		totalScoreB += turnScore;
		cout << " Your Total Score is: " << totalScoreB << "\n\n\n\n" << endl;

	}//ends else if	
}

////The following function is responsible for playerA's gameturn, no parameters, returns an integer
int playerAGameTurn() {
	char choice;////for checking keyboard inputs
	int die = 0;//To hold the game tool which shuffles random numbers from 1 to 6
	int playerATurn = 1;//to be used for player turn control always initializes to 1 when method is called

	while (playerATurn == 1) {//checks if player
	
		cout << "Player 1 roll ([R] to roll, [Q] to quit)" << endl;//instructions for player
		cin >> choice;///////////////////gets the key pressed on keyboard/////////
		if (choice == 'r') {////checks if the passed in key is for rollng the die
			die = 1 + (rand() % 6); /////////////////rolls a Die and returns a random number between 1 and 6

    //function checkRoll called and given arguments, playerBTurn here is inactive hence the zero
	////die is from above statement
			checkRoll(die, playerATurn, 0);

		//this statement makes sure the while loop terminates and the gameTurn also terminates
			playerATurn = 0;
		}//end if

		//Alternative to above if statement
		else  if (choice == 'q') {//checks if user input is q
			exit(EXIT_SUCCESS);//terminates the program
		}//ends if
	
	}
	return totalScoreA;	////returns the player's total score	
}

////The following function is responsible for playerB's gameturn, its completely simillar to the above function for playerA
int playerBGameTurn() {
	char choice;
	int die = 0;
	int playerBTurn = 1;

	while (playerBTurn == 1) {

		cout << "Player 2 roll ([R] to roll, [Q] to quit)" << endl;
		cin >> choice;///////////////////gets the key pressed on keyboard/////////
		if (choice == 'r') {
			die = 1 + (rand() % 6 ); /////////////////rolls a Die

			checkRoll(die, 0, playerBTurn);

			playerBTurn = 0;
			}
			else if (choice == 'q') {
				exit(EXIT_SUCCESS); /////exits program
			}
		} 
	return totalScoreB;
	}
	

int main(){
	char mainChoice;//for user input from main menu

	cout << "Welcome to The Dice Game! Please select from the following menu: " << endl;//main menu
	cout << "Press [p] to play, [q] to quit \n\n";//menu prompts

	cin >> mainChoice;//listens for input

	if (mainChoice == 'p') {//if input is a p

		//game begins until one of the total scores is 100
		while (totalScoreA < 100 || totalScoreB < 100)
		{
			/////////////////////gameturns alternate repeatedly til someone reaches 100 points
			playerAGameTurn();
			////Checks if PlayerA won yet 
			if (totalScoreA == 100) {
				cout << "CONGRATULATIONS********* PLAYER 1 IS THE WINNER !! *********CONGRATULATIONS\n";
				exit(EXIT_SUCCESS);/////////////////Exits the appliction
			}

			playerBGameTurn();
			////Checks if PlayerB won yet 
			if (totalScoreB == 100) {
				cout << "CONGRATULATIONS********* PLAYER 2 IS THE WINNER !! *********CONGRATULATIONS\n";
				exit(EXIT_SUCCESS);/////////////////Exits the appliction
			}
		}
	}
	else if(mainChoice == 'q')
	{
		exit(EXIT_SUCCESS);/////////////////Exits the appliction
	}	

}
