#pragma once

#include <vector>
#include <string>
using namespace std;

class output
{
public:
	output();
	~output();
	void tofile(vector<string> chain);
};