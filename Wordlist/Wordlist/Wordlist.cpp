// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <fstream>
#include <vector>
#include <string>
#include "FileInput.h"
#include "../Core/wordHandler.h"
#include "output.h"
using namespace std;

int main(int argc, char *argv[]) {
	typedef int (*gen_chain_word)(vector<string> &words, int len, vector<string> &wchain, char head, char tail, bool enable_loop);
	typedef int (*gen_chain_char)(vector<string> &words, int len, vector<string> &wchain, char head, char tail, bool enable_loop);

	FileInput fin;
	vector<string> result;
	char *ptr = argv[1];
	int i = 1;

	//char *_words[100];
	int _len = 0;
	bool con = false;
	bool recur = false;
	char head = '\0', tail = '\0';
	char fun = '\0';
	while (true)
	{
		con = false;
		switch (ptr[1])
		{
		case 'r':
			recur = true;
			con = true;
			break;
		case 'h':
			ptr++;
			head = *ptr;
			con = true;
			break;
		case 't':
			ptr++;
			tail = *ptr;
			con = true;
			break;
		case 'w':
			fun = 'w';
			break;
		case 'c':
			fun = 'c';
			break;
		default:
			break;
		}
		if (con)
		{
			i++;
			ptr = argv[i];
			continue;
		}
		else
		{
			break;
		}
	}
	try
	{
		fin.readFile(argv[i + 1]);
	}
	catch (FINException& fine)
	{
		fine.what();
		return 0;
	}
	if (fun == 'w')
	{
		wordHandler whword;
		whword.gen_chain_word(fin.inArr, fin.size, result, head, tail, recur);
	}
	else if (fun == 'c')
	{
		wordHandler whchar;
		whchar.gen_chain_char(fin.inArr, fin.size, result, head, tail, recur);
	}
	else
	{
		cout << "Invalid command!" << endl;
	}
	output chout;
	chout.tofile(result);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
