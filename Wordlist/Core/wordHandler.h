#pragma once

#include <vector>
#include <string>
using namespace std;

class wordHandler
{
public:
	wordHandler();
	~wordHandler();
	int gen_chain_word(vector<string> &words, int len, vector<string> &result, char head, char tail, bool enable_loop);
	int gen_chain_char(vector<string> &words, int len, vector<string> &result, char head, char tail, bool enable_loop);
	//vector<string> Operate(char head, char tail, vector<string> words, int length);
	bool meet_req(char head, char tail, vector<string> words);
	bool can_insert(string current, vector<string> chain);
};
