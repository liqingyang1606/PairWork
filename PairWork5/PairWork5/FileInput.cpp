#include "pch.h"
#include "FileInput.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;
FileInput::FileInput()
{
	size = 0;
}


FileInput::~FileInput()
{
}

void FileInput::process_line(char warr[]) {
	int i = 0, j = 0;
	string temp;
	while (true)
	{
		if (isalpha(warr[i]) != 0)
		{
			temp += warr[i];
			j++;
		}
		else
		{
			if (j > 0)// not an empty word
			{
				temp[j] = '\0';
				inArr.push_back(temp);
				size++;
				j = 0;
				temp.assign("");
			}
			if (warr[i] == '\0')// end of the line
			{
				break;
			}
		}
		i++;// move to the next char
	}
}
void FileInput::readFile(string path) {
	ifstream rdFile;
	rdFile.open(path);
	char wordArr[5000];
	while (!rdFile.eof())
	{
		rdFile >> wordArr;
		process_line(wordArr);
	}
	//cout << inArr.size() << endl;
	//cout << inArr.at(0) << endl;
}