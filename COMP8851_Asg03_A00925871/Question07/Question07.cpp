/*========================================================================================
	Question 07
	
	Demonstrates a recursive algorithm for generating a round-robin tournament schedule.

	Takes one command-line argument, k, to determine the number of players in the 
	tournament, which will be 2^k. An exception is thrown if the given k is less than 1.
    
    Copyright 2018 Erick Fernandez de Arteaga. All rights reserved.
        https://www.linkedin.com/in/erick-fda
        https://github.com/erick-fda
        https://bitbucket.org/erick-fda
	
========================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

/*========================================================================================
	Constants
========================================================================================*/
const string HORIZONTAL_RULE = "----------------------------------------------------------";
const int NULL_PLAYER = -1;

/*========================================================================================
	Functions
========================================================================================*/
/**
	Print the given schedule.
*/
void PrintSchedule(vector<vector<int>>& schedule)
{
	cout << "The schedule below shows the opponent for each player on each day of the " <<
		"tournament.\n\n";

	/* Print header row. */
	cout << HORIZONTAL_RULE << "\n";
	for (int player = 0; player < schedule[0].size(); ++player)
	{
		cout << player << "\t";
	}
	cout << "\n" << HORIZONTAL_RULE << "\n";

	/* Print data rows. */
	for (int day = 0; day < schedule.size(); ++day)
	{
		for (int player = 0; player < schedule[0].size(); ++player)
		{
			cout << schedule[day][player] << "\t";
		}

		cout << "\n";
	}

	cout << "\n";
}

/**
	Generates the schedule for one day of the tournament.
*/
void GenerateScheduleRecursive(vector<int>& roster, vector<vector<int>>& schedule, int N, int day)
{
	/* Generate today's matchups. */
	int halfN = N / 2;
	for (int i = 0; i < halfN; ++i)
	{
		int player = roster[i];
		int opponent = roster[N - (1 + i)];
		schedule[day][player] = opponent;
		schedule[day][opponent] = player;
	}

	/* Cycle the roster. */
	int shuffledPlayer = roster.back();
	roster.erase(roster.begin() + (N - 1));
	roster.insert(roster.begin() + 1, shuffledPlayer);

	/* Call the next iteration if we're not done yet. */
	if (day < (N - 2))
	{
		GenerateScheduleRecursive(roster, schedule, N, day + 1);
	}
}

/**
	Calls the recursive schedule generation function.
*/
void GenerateSchedule(vector<vector<int>>& schedule, int N)
{
	/* Generate the list of players to be used when determining matchups. */
	vector<int> roster = vector<int>();
	for (int player = 0; player < N; ++player)
	{
		roster.push_back(player);		// Add player to roster.
	}

	/* Generate the empty schedule for each day. */
	for (int day = 0; day < N - 1; ++day)
	{
		schedule.push_back(vector<int>());

		for (int player = 0; player < N; ++player)
		{
			schedule.back().push_back(NULL_PLAYER);
		}
	}

	GenerateScheduleRecursive(roster, schedule, N, 0);
}

/*========================================================================================
	Main Function
========================================================================================*/
int main(int argc, char* argv[])
{
	cout << HORIZONTAL_RULE << "\n\tQuestion 07\n" << HORIZONTAL_RULE << "\n\n";

	/* Read and validate parameter. */
	if (argc < 2)
	{
		cout << "ERROR: You must provide a positive int parameter, k.\n\n";
		return 1;
	}

	int k = std::stoi(argv[1]);

	if (k < 1)
	{
		cout << "Parameter k must be greater than zero.\n\n";
		return 1;
	}

	int N = pow(2, k);

	cout << "Given parameter k was " << k << ".\n";
	cout << "Generating round-robin tournament schedule for " << N << " players.\n\n";

	/* 
		Nested vector for result.
		The outer vector is the list of days.
		Each inner vector is the list of matches on a given day.

		For each inner vector, the int at each index i indicates the index of the player to play 
		against the player with index i.

		Player indices will be [0-(N-1)].
	*/
	vector<vector<int>> schedule = vector<vector<int>>();

	/* Generate and print the schedule. */
	GenerateSchedule(schedule, N);
	PrintSchedule(schedule);
	
	cout << "Press Enter to quit...\n";
	cin.ignore();
	return 0;
}
