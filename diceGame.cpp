#include<iostream>
using namespace std;

enum Player { PA, PB };
int totalScoreA = 0;//Total score for player A
int totalScoreB = 0;//Total score for player B

int performRoll(Player player){
	char choice;
	int die = 0;
	char current = player == PA ? 'A' : 'B';
	cout << "Player "<< current <<"'s turn"<< endl;
	cout << "Press ([R] to roll or [Q] to quit)" << endl;

	while(true){
		cin >> choice;//gets the key pressed on keyboard
		if (choice == 'r' || choice == 'R') {
			die = 1 + (rand() % 6 ); //Die roll sim
			break;
		}
		else if (choice == 'q' || choice == 'Q') {
			exit(EXIT_SUCCESS); 
			break;
		}
		else{
			cout << "Invalid input try again" << endl;
		}
	}
	return die;
}

//This function checks the number rolled by the dice, if a player rolled a six, they play again. If they roll a six 3 times, their turn is ended //and they don't get to play again.
void checkRoll(int die, Player player) {
	int sixTurn = 0;//A control for turns played when a player rolls a six (only 3 allowed)

	beginCheck ://label to check if player has rolled a six again

	//check if a player rolled a six
	if (die == 6) {
		cout << "You rolled a SIX, roll again!!\n";
		++sixTurn;
			//Check if its playerA's turn is and if its not the third time they roll
			if ((player ==  PA) && !(sixTurn == 2)) {
				totalScoreA += die;//increments totalScore
				cout << "Player A Total score: " << totalScoreA << endl;//shows current score

				die = performRoll(player); 

				goto beginCheck;//returns program to label so we check if die is six
			}
			else if ((player  ==  PB) && !(sixTurn == 2)){
				//for playerB
				totalScoreB += die;
				cout << "Player B Total score: " << totalScoreB << endl;

				die = performRoll(player);

				goto beginCheck;
			}
			else if (sixTurn == 2)
			{
				//Check if Either player (A or B) has rolled  a 6 for the third time and skip their turn
				cout << "Now you're cheating!\n\n\n";
			}
	}
	else if (die  < 6)
	{
		cout << "You rolled a: " << die << endl;
		if(player == PA) {
			totalScoreA += die;
			cout << "Player A Total Score is: " << totalScoreA << endl;
			cout << "Scores [PA: " << totalScoreA << ", PB: "  << totalScoreB <<"]" << "\n\n" << endl;
		}else{
			totalScoreB += die;
			cout << "Player B Total Score is: " << totalScoreB << endl;
			cout << "Scores [PA: " << totalScoreA << ", PB: "  << totalScoreB <<"]" << "\n\n" << endl;
		} 	
	}
}


//function for a player's gameturn
void gameTurn(Player player) {
	int die = performRoll(player);
	checkRoll(die, player); 
}
	

int main(){
	char mainChoice;//for user input from main menu
	enum Player player = PA;

	cout << "Welcome to The Dice Game! Please select from the following menu: " << endl;
	cout << "Press [p] to play, [q] to quit \n\n";

	cin >> mainChoice;

	if (mainChoice == 'p' || mainChoice == 'P') {

		//game runs until one of the total scores is 100
		while (true)
		{
			//gameturns alternating
			gameTurn(PA);
			//Checks if PlayerA won yet 
			if (totalScoreA >= 100) {
				cout << "CONGRATULATIONS********* PLAYER A IS THE WINNER !! *********CONGRATULATIONS\n";
				exit(EXIT_SUCCESS);//Exits the appliction
			}

			gameTurn(PB);
			if (totalScoreB >= 100) {
				cout << "CONGRATULATIONS********* PLAYER B IS THE WINNER !! *********CONGRATULATIONS\n";
				exit(EXIT_SUCCESS);
			}
		}
	}
	else if(mainChoice == 'q' || mainChoice == 'Q')
	{
		exit(EXIT_SUCCESS);
	}	

}
