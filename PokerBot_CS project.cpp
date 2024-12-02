#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


//structure
struct Card 
{
    string suit;
    string rank;
};

// Function to generate a random card
Card dealCard() 
{
	//arrays
    string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

	//randomly selects the cards
    return {suits[rand() % 4], ranks[rand() % 13]};
}

// Function to evaluate the strength of a hand
int evaluateHandStrength(const vector<Card> &hand) 
{
    int strength = 0;
    
    for (const auto& card : hand)
	{
			
		//calculates stengths for suits
        if (card.rank == "Ace") 
		{
            strength += 14;
        } 
		else if (card.rank == "King")
		{
            strength += 13;
        }
		else if (card.rank == "Queen") 
		{
            strength += 12;
        }
		else if (card.rank == "Jack")
		{
            strength += 11;
        } 
		else 
		{
			//for any number "stoi" converts string to integer
            strength += stoi(card.rank);
        }
    }
    return (strength);
}

// Function to display a hand
void displayHand(const vector<Card>& hand) 
{
    for (const auto& card : hand) 
	{
        cout << card.rank << " of " << card.suit << endl;
    }
}

// Function for AI decision-making
string makeAIDecision(int handStrength) 
{
    if (handStrength > 15) 
	{
        return "Raise";
    } 
	else if (handStrength > 10) 
	{
        return "Call";
    } 
	else 
	{
        return "Fold";
    }
}

int main() 
{
	int input1, input2;
	char again;
	
	//do while to go again
	do
	{
		//first input
		cout << "\n" "Press 1 to deal" << endl;
		cin >>  input1;
	
		if (input1 == 1)
		{
    
			// Seed the random number generator
    		srand(static_cast<unsigned>( time(0) ) );

    		vector<Card> playerHand, aiHand;

    		// Deal two cards to each player
    		for (int i = 0; i < 2; ++i) 
			{
    		    playerHand.push_back(dealCard());
    		    aiHand.push_back(dealCard());
    		}

    		// Display the player's hand
    		cout << "Your hand:" << endl;
    		displayHand(playerHand);

    		// Evaluate hand strengths
    		int playerStrength = evaluateHandStrength(playerHand);
    		int aiStrength = evaluateHandStrength(aiHand);
	
		    cout << "\n" "Your hand strength: " << playerStrength << endl;
		
			//second input
			cout << "\n" "Press" "\n" "1.Call " "\n" "or" "\n" "2.Fold" << endl;
			cin >> input2;
		
			if (input2 == 1)
			{
		    	// AI decision
				string aiDecision = makeAIDecision(aiStrength);
	
    			cout << "\n" "The AI is thinking..." << endl;
				cout << "The AI chooses to: " << aiDecision << endl;

    			// Simple game conclusion
    			cout << "\n" "AI's hand:" << endl;
    			displayHand(aiHand);
    			cout << "AI hand strength: " << aiStrength << endl;
    		
    			//win or lose condition
    			if (playerStrength > aiStrength) 
				{
    			    cout << "\n" "You win!" << endl;
    			} 
				else if (playerStrength < aiStrength) 
				{
    			    cout << "\n" "AI wins!" << endl;
    			} 
				else 
				{
    			    cout << "\n" "It's a tie!" << endl;
				}
			}
		}
		
		//else condition for input 1
    	else
		{
			cout << "Ayy play the damn game!" << endl;
		}
		
		//prompt the user to go again
		cout << "Go again? (Y/N)" << endl;
		cin >> again;
		
	}
	while (again != 'N' || again != 'n');
	
	
    return 0;
}
