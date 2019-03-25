#pragma once
#include <vector>
#include <string>
#include <exception>
using namespace std;
class FileInput
{
public:
	FileInput();
	~FileInput();
	vector<string> inArr;// Collection of words in the input text
	int size;// the number of words in 'inArr'
	bool readFile(string path);
	void process_line(char warr[]);
};

class FINException:public exception
{
public:
	FINException();
	~FINException();

private:

};
