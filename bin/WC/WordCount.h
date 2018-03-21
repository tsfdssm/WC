#pragma once
#include <vector>
#include<string>
class WordCount
{
public:
	WordCount();
	~WordCount();
	int _c(char*);

	int _w(char*);

	int _l(char*);

	bool _o(char*);

	bool _s(char*);

	bool _a(char *);

	bool _e(char*);

	void _x();


	std::vector<std::string>res;
	std::vector<std::string>stoplist;
	std::vector<int>lines;
};