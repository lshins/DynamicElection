#include <iostream>
#include <iomanip>
#include <string>
#include "candidate.h"

using namespace std;

int main()
{
	cout << "Welcome to the Dynamic Election program!" << endl << endl;
	char c;
	do
	{
		cout << "Input the number of candidates in this election." << endl << endl;
		int n;
		cin >> n;
		while (n <= 0)
		{
			cout << endl;
			cout << "Invalid number of candidates. Please input a valid number." << endl;
			cin >> n;
		}
		cout << endl;
		cin.ignore(1000, '\n');
		candidate* runners = new candidate[n];
		double votesTotal = 0;
		for (int i = 0; i < n; i++)
		{
			cout << "Candidate #" << i + 1 << endl << endl;
			runners[i].setInfo();
			votesTotal += runners[i].returnVotes();
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			runners[i].calcPercent(votesTotal);
			runners[i].print();
		}
		cout << endl;
		int winnerIndex = 0;
		int mostVotes = runners[0].returnVotes();
		for (int i = 1; i < n; i++)
			if (runners[i].returnVotes() > mostVotes)
			{
				mostVotes = runners[i].returnVotes();
				winnerIndex = i;
			}
		cout << "The winner of the election is ";
		runners[winnerIndex].printName();
		cout << " with " << runners[winnerIndex].returnVotes() << " votes (" << showpoint << fixed << setprecision(1) << runners[winnerIndex].returnPercent() << "% of the total vote)." << endl << endl << endl;
		delete[] runners;
		runners = 0;
		cout << "To continue, press 'c'." << endl;
		cout << "To terminate the program, press any other key." << endl << endl;
		cin >> c;
		cout << endl;
	} while (c == 'c');
	return 0;
}