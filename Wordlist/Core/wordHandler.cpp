#include "stdafx.h"
#include "wordHandler.h"

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <string.h>

wordHandler::wordHandler()
{
}


wordHandler::~wordHandler()
{
}

bool wordHandler::meet_req(char head, char tail, vector<string> words) {
	bool bh, bt;
	int lve, lst;
	if (head != 0)
	{
		bh = (words[0].at(0) == head);
	}
	else
	{
		bh = true;
	}
	if (tail != 0)
	{
		lve = words.size();
		lst = words[lve - 1].length();
		bt = (words[lve - 1].at(lst - 1) == tail);
	}
	else
	{
		bt = true;
	}
	return (bh && bt);
}
bool wordHandler::can_insert(string current, vector<string> chain) {
	int length = chain.size();
	for (int i = 0; i < length; i++)
	{
		if (current.compare(chain[i]) == 0)
		{
			return false;// cannot insert
		}
	}
	return true;
}
// calculate the length regarding the number of words
int wordHandler::gen_chain_word(vector<string> &words, int len, vector<string> &wchain, char head, char tail, bool enable_loop) {
	char front, rear;
	int cur;
	int i = 0;
	int j, k = 0;
	int size = len;
	int count = 1;
	int tcnt = 0;
	int length;
	//int res[32];
	vector<string> tchain;
	bool flag = false;

	while (i < size) {
		flag = false;
		tchain.clear();
		k = 0;
		tchain.push_back(words[i]);
		length = words[i].size();
		rear = words[i].at(length - 1);
		cur = i;
		count = 1;
		for (j = 0; j < size; j++) {
			if (j == cur) {
				continue;
			}
			front = words[j].at(0);
			if (front == rear) {
				if (!can_insert(words[j], tchain))
				{
					continue;
				}
				count++;
				tchain.push_back(words[j]);// current rear of the chain
				length = words[j].size();
				rear = words[j].at(length - 1);
				k++;
				flag = true;
			}
			if (flag)
			{
				flag = false;
				continue;
			}
		}
		// check if this chain meet with the requirements
		if (meet_req(head, tail, tchain) && count > tcnt) {
			wchain = tchain;
			tcnt = count;
		}
		i++;
	}
	if (wchain.empty()) {
		cout << "No chain could be found!" << endl;
	}
	return tcnt;
}

// calculate the length regarding the number of characters
int wordHandler::gen_chain_char(vector<string> &words, int len, vector<string> &wchain, char head, char tail, bool enable_loop)
{

	int cur;
	int i = 0, j, k;
	int charCnt = 0;
	int tcharCnt = 0;
	vector<string> tchain;
	bool flag = false;
	int size = len;
	char front, rear;
	int length;

	while (i < size)
	{
		k = 0;
		tchain.clear();
		tchain.push_back(words[i]);
		charCnt = words[i].size();
		length = words[i].size();
		rear = words[i].at(length - 1);
		cur = i;
		for (j = 0; j < size; j++)
		{
			if (j == cur) {
				continue;
			}
			front = words[j].at(0);
			if (front == rear)
			{
				if (!can_insert(words[j], tchain))
				{
					continue;
				}
				tchain.push_back(words[j]);
				charCnt += words[j].size();
				length = words[j].size();
				rear = words[j].at(length - 1);
				flag = true;
				j = -1;
			}
			if (flag)
			{
				flag = false;
				continue;
			}
		}
		// check if this chain meet with the requirements
		if (meet_req(head, tail, tchain) && charCnt > tcharCnt)
		{
			wchain = tchain;
			tcharCnt = charCnt;
		}
		i++;
	}
	if (wchain.empty()) {
		cout << "No chain could be found!" << endl;
	}
	/*if (head != 0 || tail != 0) {
		wordHandler::Operate(head, tail, tchain, tchain.size());
	}*/
	return wchain.size();
}