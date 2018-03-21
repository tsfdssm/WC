#include "WordCount.h"

#include<iostream>
#include<io.h>
#include<fstream>
#include<Windows.h>
#include<string>
#include <vector>

using namespace std;

vector<string>res;
vector<string>stoplist;
vector<int>lines;


WordCount::WordCount()
{
	lines.push_back(0);
	lines.push_back(0);
	lines.push_back(0);
}

WordCount::~WordCount()
{
}

int WordCount::_c(char * file)
{
	////
	ifstream fin;
	int count = 0;
	char ch;

	fin.open(file);
	if (!fin.is_open())	//检测文件是否成功打开
	{
		cerr << "Could not open" << file << endl;
		fin.clear();
		fin.close();
		return -1;
	}

	while (fin.get(ch))
		count++;	//counting

	fin.clear();
	fin.close();

	return count;//返回计数值
}

int WordCount::_w(char *file)
{
	////
	ifstream fin;
	int word = 1;

	fin.open(file);
	if (!fin.is_open())	//检测文件是否成功打开
	{
		cerr << "Could not open" << file << endl;
		fin.clear();
		fin.close();
		return - 1;
	}

	while(!fin.eof())
	{
		char cw = fin.get();
		char cp = fin.peek();
		if (!((cw == ' ')|| (cw == '\0')||(cw == '\t' )||( cw == '\n') || (cw == ',')))
		{
			if((cp == ' ') || (cp == '\0') || (cp == '\t') || (cp == '\n') || (cp == ','))
			{
				word++;
			}
		}

	}
	fin.clear();
	fin.close();

	return word;//返回计数值
}

int WordCount::_l(char * file)
{
	ifstream fin;
	int count =1;

	fin.open(file);
	if (!fin.is_open())	//检测文件是否成功打开
	{
		cerr << "Could not open" << file << endl;
		fin.clear();
		fin.close();
		return -1;
	}
	while (!fin.eof())
	{
		if (fin.get()=='\n')
		{ 
			++count;
		}

	}
	fin.clear();
	fin.close();

	return count;//返回计数值
}

bool WordCount::_o(char *file)
{
	ifstream fin;
	fin.open(file);
	if (!fin.is_open())	//检测文件是否成功打开
	{
		fin.clear();
		fin.close();
		return false;
	}
	else 
	{
		return true;
	}
}

bool WordCount::_s(char *file)
{
	char dirNew[200];
	strcpy_s(dirNew, file);
	strcat_s(dirNew, "\\*.*");    // 在目录后面加上"\\*.*"进行第一次搜索


	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(dirNew, &findData);
	
	if (handle == -1)        // 检查是否成功
		return false;
	do
	{
		if (findData.attrib & _A_SUBDIR)
		{
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;

			//cout << findData.name << "\t<file>\n";

			// 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
			strcpy_s(dirNew, file);
			strcat_s(dirNew, "\\");
			strcat_s(dirNew, findData.name);
			//res.push_back(findData.name);
			_s(dirNew);
		}
		else
		{ 
			strcpy_s(dirNew, file);
			strcat_s(dirNew, "\\");
			strcat_s(dirNew, findData.name);
			res.push_back(dirNew);//cout << findData.name << "\t" << findData.size << " bytes.\n";
		}
			
	} while (_findnext(handle, &findData) == 0);

	_findclose(handle);    // 关闭搜索句柄
	return true;
}

bool WordCount::_a(char *file)
{
	ifstream fin;
	int codeline = 0, emptyline = 0, noteline = 0;
	string temp1,temp2;
	temp2 = "//";
	char temp[50];

	lines[0] = codeline;
	lines[1] = emptyline;
	lines[2] = noteline;

	fin.open(file);
	if (!fin.is_open())	//检测文件是否成功打开
	{
		cerr << "Could not open" << file << endl;
		fin.clear();
		fin.close();

		return false;
	}
	while (!fin.eof())
	{
		fin.getline(temp,50);
		temp1 = temp;
		
		if (temp1.length() > 1)
		{
			if (temp1.find(temp2) == string::npos)
			{
				++codeline;
			}
			else
			{
				++noteline;
			}
		}
		else
		{
			++emptyline;
		}
		temp1 = codeline + "\\" + emptyline ;
		
	}
	fin.clear();
	fin.close();


	lines[0]=codeline;
	lines[1]=emptyline;
	lines[2]=noteline;
	return true;
}

bool WordCount::_e(char *stoplistfile)
{
	////
	ifstream fin;
	fin.open(stoplistfile);
	if (!fin.is_open())	//检测文件是否成功打开
	{
		cerr << "Could not open" << stoplistfile << endl;
		fin.clear();
		fin.close();
		return false;
	}
	else
	{	
		string stopwords="";
		while (1)
		{
			char cw=fin.get();
			//cout << cw << endl;
			if ((cw == ' ')||(cw=='\n')||fin.eof() )
			{
				if (stopwords.size() >= 1)//&&!(stopwords.find('\0'))
				{
					stoplist.push_back(stopwords);
					//cout << stopwords << "111111"<<endl;
					stopwords = "";
				}
				if (fin.eof())
				{
					break;
				}
				else
				{
					continue;
				}
			}
			else
			{
				stopwords += cw;
				//cout << stopwords<<endl;
			}
		}
	}
	return true;
}

void WordCount::_x()
{
	WinExec("WordCountUI.exe", SW_NORMAL);
}



