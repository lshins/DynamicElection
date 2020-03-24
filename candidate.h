#ifndef H_candidate
#define H_candidate

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class candidate
{
	string first, last;
	int votes;
	double percent;

public:
	void print();
	void printName();
	int returnVotes();
	double returnPercent();
	void calcPercent(double);
	void setInfo();
	candidate();
	~candidate();
};

#endif