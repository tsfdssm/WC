#include"WordCount.h"

#include<iostream>
#include<string>
#include<vector>
#include<fstream>


using namespace std;

const int FILE_NAME = 160;
bool parameter(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	if (argc < 1)
	{
		cout << "error" << endl;
		return 0;
	}
	//argc = 8;
	//argv[0] = "wc.exe";
	//argv[1] = "-c";
	//argv[2] = "-wfgh";
	//argv[3] = "a";
	//argv[4] = "-e";
	//argv[5] = "resultbbhnjt.txt";
	//argv[6] = "-l";
	//argv[7] = "-a";
	
	/*cout <<endl<<"end";*/

	parameter(argc,argv);

	cin.get();
	return 0;
}
bool parameter(int argc, char *argv[])
{
	int parameter[9] = { 0 ,0,0,0,0,0,0,0,0,};//0,-c,-w,-l,-o,-s,-a,-e,-x
	vector<string>pars,output_file,stop_file,open_file;
	WordCount aWordCount;
	ofstream fout;
	for (int i = 1;i < argc;++i)
	{
		pars.push_back(argv[i]);
		/*cout << argv[i];
		cin.get();*/
	}
	for (int i = 0;i < pars.size();++i)
	{
		/*cout << i;
		cin.get();*/
		if (!(pars[i].find("-c") == string::npos))
		{
			parameter[1] = 1;
			pars[i] = "";
		}
		if (!(pars[i].find("-w") == string::npos))
		{
			parameter[2] = 1;
			pars[i] = "";
		}
		if (!(pars[i].find("-l") == string::npos))
		{
			parameter[3] = 1;
			pars[i] = "";
		}
		if ((!(pars[i].find("-o") == string::npos))&&(i<pars.size()-1))
		{
			parameter[4] = 1;
			output_file.push_back( pars[i + 1]);
			pars[i] = "";
			pars[i+1] = "";
		}
		if (!(pars[i].find("-s") == string::npos))
		{
			parameter[5] = 1;
			pars[i] = "";
		}
		if (!(pars[i].find("-a") == string::npos))
		{
			parameter[6] = 1;
			pars[i] = "";
		}
		if (!((pars[i].find("-e") == string::npos))&& (i<pars.size() - 1))
		{
			parameter[7] = 1;
			stop_file.push_back(pars[i + 1]);
			pars[i] = "";
			pars[i+1] = "";
		}
		if (!(pars[i].find("-x") == string::npos))
		{
			parameter[8] = 1;
			pars[i] = "";
		}
		else
		{

		}
	}
	if (1 == parameter[8])
	{
		cout << parameter[8];
		cin.get();
		aWordCount._x();
		return true;
	}
		//检查输出文件或目录能否打开
		if (0 == output_file.size())
		{
			output_file.push_back("result.txt");
		}
		
		for(int i=0;i<=output_file.size();++i)
		{	
			/*cout << output_file.size()<< endl;
			cin.get();*/
			char* a = new char[output_file[i].size() + 1];
			a=const_cast<char*>(output_file[i].c_str());
			if (!(aWordCount._o(a)))
			{
				cout << "cannot open this output_file:" << output_file[i]<< endl;
				return false;
			}
			else
			{
				cout << "success open this output_file:" << output_file[i]<< endl;
			}
			++i;
		} 

		//检查禁用文件能否打开
		if (1==parameter[7])
		{
			//cout << parameter[7];
			if(0 == stop_file.size())
			{ 
				cout << "没有禁用文件" << endl;
				return false;
			}
			else
			{
				for(int j=0;j<=stop_file.size();++j)
				{
					char* a = new char[stop_file[j].size() + 1];
					a = const_cast<char*>(stop_file[j].c_str());
					if (!(aWordCount._o(a)))
					{
						cout << "cannot open this stop_file:" << stop_file[j] << endl;
			
						break;
					}
					++j;
		
				}
			}		
		}

		//得到目标文件
		for (int i = 0;i < pars.size();++i)
		{
			if (pars[i] != "")
			{
				char* a = new char[pars[i].size() + 1];
				a = const_cast<char*>(pars[i].c_str());
				aWordCount._s(a);
				for (int j = 0;j < aWordCount.res.size();++j)
				{
					open_file.push_back(aWordCount.res[j]);
				}
	
			}
		}
		
		//检查目标文件是否能打开
		if  (0 == open_file.size())
		{

			cout << "没有目标文件" << endl;
			return false;
		}

		for(int k=0;k<=open_file.size();++k)
		{
			char* a = new char[open_file[k].size() + 1];
			a = const_cast<char*>(open_file[k].c_str());
			if (!(aWordCount._o(a)))
			{
				cout << "cannot open this open_file:" << open_file[k] << endl;
				
				break;
			}
			++k;
			//delete[] a;
			//a = NULL;
		}

		/*for (int i = 0;i < 9;++i)
		{
			cout << parameter[i]<<endl;
		}

		for (int i = 0;i < pars.size();++i)
		{
			cout << pars[i]<<endl;
		}

		for (int i = 0;i < open_file.size();++i)
		{
			cout << open_file[i] << endl;
		}*/
		//输出到文件夹并显示。
		for (int i=0;i<open_file.size();++i)
		{
			char* a = new char[open_file[i].size() + 1];
			a = const_cast<char*>(open_file[i].c_str());
			cout << open_file[i] << ":" << "\t\t\t\t" << endl;
			if (parameter[1])
			{
				cout << open_file[i] << ":" << "字符数为：" << aWordCount._c(a)<<endl;
			}
			if (parameter[2])
			{
				cout << open_file[i] << ":" << "单词数为：" << aWordCount._w(a)<<endl;
			}
			if (parameter[3])
			{
				cout << open_file[i] << ":" << "行数为：" << aWordCount._l(a)<<endl;
			}
			if (parameter[6])
			{
				aWordCount._a(a);
				cout << open_file[i] << ":" << "代码行/空行/注释行为：" << aWordCount.lines[0]<<"/"<<aWordCount.lines[1]<<"/"<<aWordCount.lines[2]<<endl;
			}
			cout << endl;
		}
		for (int j=0;j<output_file.size();++j)
		{
			fout.open(output_file[j]);
			for (int i = 0;i<open_file.size();++i)
			{
				char* a = new char[open_file[i].size() + 1];
				a = const_cast<char*>(open_file[i].c_str());
				//fout << open_file[i] << ":"  << endl;
				if (parameter[1])
				{
					fout << open_file[i] << ":" << "字符数为：" << aWordCount._c(a) << endl;
				}
				if (parameter[2])
				{
					fout << open_file[i] << ":" << "单词数为：" << aWordCount._w(a) << endl;
				}
				if (parameter[3])
				{
					fout << open_file[i] << ":" << "行数为：" << aWordCount._l(a) << endl;
				}
				if (parameter[6])
				{
					aWordCount._a(a);
					fout << open_file[i] << ":" <<"代码行/空行/注释行为：" << aWordCount.lines[0] << "/" << aWordCount.lines[1] << "/" << aWordCount.lines[2]<<endl;
				}
				fout << endl;
			}

		}
		cout <<"success!"<<endl<<"已输入到目标文件夹："<<endl;
		for (int i = 0;i < output_file.size();++i)
		{
			cout << output_file[i] << endl;
		}
		return true;

}

