#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>
#include <string>

using namespace std;

class Monopoly_Simulation
{
	
public:
	int location = 0; //Current location
	int count_double = 0; // Check consecutive doubles
	int total; // Total roll
	map<int, int> watch_steps; //Finished count squares
	
	vector<string> map  
	{
		"GO","A1","CC1","A2","T1","R1","B1","CH1","B2","B3","JAIL",
		"C1","U1","C2","C3","R2","D1","CC2","D2","D3","FP",
		"E1","CH2","E2","E3","R3","F1","F2","U2","F3","G2J",
		"G1","G2","CC3","G3","R4","CH3","H1","T2","H2"
	};
	
	vector<string> community_card
	{
		"Advance to go","Go to jail","","", "", "", "", "", "", "",
		"", "", "", "", "", ""
	};
	vector<string> chance_card
	{
		"Advance to go","Go to jail","Go to C1","Go to E3","Go to H2","Go to R1","Go to next R","Go to next R"
		,"Go to next U","Go back 3 squares","", "", "", "", "", ""
	};


	void refresh() // New game 
	{
		total = 0;
		count_double = 0;
		location = 0;
		watch_steps.clear();
		for(int i = 0; i < 40; i++)
		{
			watch_steps[i] = 0;
		}
	};
	
	int roll_dice() 
	{
		int dice_1 = 1 + rand() % 4;
		int dice_2 = 1 + rand() % 4;
		if (dice_1 == dice_2)
		{
			count_double++;
		}
		else
		{
			count_double = 0;
		}
		return dice_1 + dice_2;
	}

	void card_top_to_bottom(vector<string> &card) 
	{
		auto first = card[15];
		card.pop_back();
		card.insert(card.begin(), first);
	}

	void play_cc_cards()
	{
		string card = community_card[0];
		
		if (card == "Advance to go")
		{
			location = 0;
		}
		else if( card == "Go to jail")
		{
			location = 10;
		}
		card_top_to_bottom(community_card);
		
	}

	void play_ch_cards()
	{
		string card = chance_card[0];
		if (card == "Advance to go")
			location = 0;
		else if (card == "Go to jail")
			location = 10;
		else if (card == "Go to C1")
			location = 11;
		else if (card == "Go to E3")
			location = 24;
		else if (card == "Go to H2")
			location = 39;
		else if (card == "Go to R1")
			location = 5;
		else if (card == "Go to next R")
		{
			int temp = location / 5;
			temp += ((temp % 2) ? 2 : 1);
			location = (temp * 5) % 40;
		}
		else if (card == "Go to next U")
			location = (location > 28) ? 12 : 28;
		else if (card == "Go back 3 squares")
			location -= 3;

		card_top_to_bottom(chance_card);
	}


	
	void game_on(int limit)
	{
		refresh();
		total = limit;
		for(int i = 0; i < limit;i++)
		{
			int dice = roll_dice(); // Roll dice
			if (count_double == 3) // Check doubles
			{
				location = 10;
				count_double = 0;
				watch_steps[location]++;
				continue;
			}
			
			location = (location + dice) % 40; // location update
				
			if (map[location].rfind("CC") != string::npos) // Check cc cards
			{
				play_cc_cards();
			}

			if (map[location].rfind("CH") != string::npos) // Check ch cards
			{
				play_ch_cards();
			}

			if (location == 30) // Check G2j
				location = 10;

			watch_steps[location]++; //Update finished squares
			
		}
		
	}

	void print_answer()
	{
		pair<int, int> first, second, third;
		for (auto x : watch_steps)
		{
			if (x.second > first.second)
			{
				pair<int, int> temp = first;
				pair<int, int> temp2 = second;
				first = x;
				second = temp;
				third = temp2;
			}
				
			else if (x.second > second.second)
			{
				pair<int, int> temp = second;
				second = x;
				third = temp;
			}
				
			else if (x.second > third.second)
			{
				third = x;
			}

		}
		cout << first.first << " -- " << (float)first.second * 100 / total << endl;
		cout << second.first << " -- " << (float)second.second * 100 / total << endl;
		cout << third.first << " -- " << (float)third.second * 100 / total << endl;
		cout << "==================================" << endl;

	}
	
};


int main()
{
	srand((unsigned int)time(NULL));
	Monopoly_Simulation s;
	for(int x = 0; x < 10; x++)
	{
		s.game_on(200000);
		s.print_answer();
	}
}
