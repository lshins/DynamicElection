#include <iostream>
#include <iomanip>
#include <string>
#include "candidate.h"

void candidate::print()
{
	cout << "Candidate" << setw(20) << right << setfill('-') << first << " " << last << endl;
	cout << "Votes Cast for Candidate" << setw(20) << right << setfill('-') << votes << endl;
	cout << "Percent of Votes Cast for Candidate" << setw(20) << right << setfill('-') << showpoint << fixed << setprecision(1) << percent << "%" << endl;
	cout << endl;
}

void candidate::printName()
{
	cout << first << " " << last;
}

int candidate::returnVotes()
{
	return votes;
}

double candidate::returnPercent()
{
	return percent;
}

void candidate::calcPercent(double vT)
{
	percent = (static_cast <double> (votes) / static_cast <double> (vT)) * 100;
}

void candidate::setInfo()
{
	cout << "Input the candidate's first name." << endl << endl;
	cin >> first;
	cout << endl;
	cout << "Input the candidate's last name." << endl << endl;
	cin >> last;
	cout << endl;
	cout << "Input the amount of votes the candidate received." << endl << endl;
	cin >> votes;
	while (votes < 0)
	{
		cout << endl;
		cout << "Invalid amount of votes. Please nput the amount of votes the candidate received." << endl << endl;
		cin >> votes;
	}
	cout << endl;
}

candidate::candidate()
{
	first = "Jane";
	last = "Doe";
	votes = 0;
	percent = 0;
}

candidate::~candidate()
{

}