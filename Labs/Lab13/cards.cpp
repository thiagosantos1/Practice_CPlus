// Thiago Santos
// Lab 13
// 12/01/2015

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;
const int NUMBCARDS = 13;

struct Card
{
	int card_value; // 1 represent Ace, 11 Jack, 12 Queen, 13 king
	int suit; // 1 represets spades, 2 hearts, 3 diamonds, and 4 clubs
	
};

std::ostream & operator<<(std::ostream & out, const Card & card){

	string suit;
	if (card.suit == 4)
		suit = "Spades";
	else if (card.suit == 3)
		suit = "Hearts";
	else if (card.suit == 2)
		suit = "Diamonds";
	else
		suit = "Clubs";

	out << "Card Value: " << card.card_value << " " <<suit;

	return out;
}

void setGameCards(vector<Card> & pack){

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < NUMBCARDS; j++)
		{
			Card temp = {j+1, i+1}; // create the cards 1 to 13 for each suit
			pack.push_back(temp);
		}
		
	}

	random_shuffle( pack.begin(), pack.end() );

}

void setPlayersCards(vector< vector<Card> > & hand, const vector<Card> & pack, const int numberOfPlayers){

	int gameCards = 0;  // save the position of the gameCards, 0 to 51. It's where we get the cards for each player

	for (int handPlayer = 0; handPlayer < numberOfPlayers; handPlayer++)
	{
		for (int j = 0; j < NUMBCARDS; j++)
		{	
			Card temp = pack[gameCards];
			hand[handPlayer].push_back(temp);
			gameCards++; // next card in the pack
		}

		//cout<<hand[handPlayer].size()<<endl;  // check if each hand has 13 cards
		
	}


}

void runGame(vector< vector<Card> > & hand, int numberOfPlayers =0){
	
	int highestCard=-1; // save the highest card of each shout
	int playerWithHighestCard = -1;
	vector<int> playersScores (4,0);
	

	// game logic
	for (int i = 0; i < NUMBCARDS; i++)  // run the logic for 13 times (how many cards each player has in hand)
	{
		// loop to print the players hands
		for (int handPlayer = 0; handPlayer < numberOfPlayers; handPlayer++) // loop for each player hand
		{	
			cout<<"\n     Player "<<handPlayer+1 <<"'s hand" <<endl;
			cout<<hand[handPlayer][hand[handPlayer].size()-1] <<endl; 
		}

		// loop to calculate who won the round
		for (int handPlayer = 0; handPlayer < numberOfPlayers; handPlayer++) // loop for each player hand
		{	
			// check if the card from the player is the highest from the shout
			if(hand[handPlayer][hand[handPlayer].size()-1].card_value > highestCard){

				highestCard = hand[handPlayer][hand[handPlayer].size()-1].card_value;
				playerWithHighestCard = handPlayer;
			}

			// check if there is a tie in the number, then we have to check by the suit
			else if(hand[handPlayer][hand[handPlayer].size()-1].card_value == highestCard){
				// check if the currently handPlayer suit is highest than the player that currencly has the highest card 
				if (hand[handPlayer][hand[handPlayer].size()-1].suit >  
					hand[playerWithHighestCard][hand[playerWithHighestCard].size()-1].suit){

					highestCard = hand[handPlayer][hand[handPlayer].size()-1].card_value;
					playerWithHighestCard = handPlayer;
				}
			}	
		}

		// loop to delete the last card of each hand, right after calculate who won the round
		for (int handPlayer = 0; handPlayer < numberOfPlayers; handPlayer++) // loop for each player hand
		{	
			hand[handPlayer].pop_back();
		}

		cout<<"Congratulations Player" <<playerWithHighestCard+1 << ",You won this round" <<endl;
		playersScores[playerWithHighestCard]++; // increment the score of the winner
		highestCard=-1; // save the highest card of each shout
		playerWithHighestCard = -1;
		string pause;
		cout<<"\n\t\tPress Enter to go continue!!!"<<endl;
		std::getline(std::cin, pause);
		
	}

	// check with player won the game
	int highestScore = *max_element(playersScores.begin(), playersScores.end() );
	for (int i = 0; i < playersScores.size(); i++)
	{
		if (playersScores[i] == highestScore)
		{
			cout<<"\n\t\tCongratulations Player"<<i+1 << ", You won the game!!\n"<<endl;
			break;
		}
	}

}

int main(int argc, char const *argv[])
{

	srand(unsigned(time(NULL)));
	vector<Card> pack;
	setGameCards(pack);
	
	/*  // print cards from the pack
	for (int i = 0; i < pack.size(); i++)
	{
		cout<<pack[i]<<endl;
	}*/

	const int numberOfPlayers=4;

	vector< vector<Card> > hand(numberOfPlayers);

	setPlayersCards(hand, pack, numberOfPlayers);

	/*  // print cards of each hand
	for (int i = 0; i < hand[0].size(); i++)
	{
		cout<<hand[0][i]<<endl;

	}*/

	runGame(hand, numberOfPlayers);

	

	return 0;
}










