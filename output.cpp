#include "pch.h"
#include "output.h"


#include <vector>
#include <string>
#include <fstream>
using namespace std;
output::output()
{
}


output::~output()
{
}

void output::tofile(vector<string> chain) {
	ofstream outfile;
	outfile.open("solution.txt");
	int n = chain.size();
	for (int i = 0; i < n; i++)
	{
		outfile << chain.at(i) << endl;
	}
	outfile.close();
}