#include<iostream>
#include<fstream> 
using namespace std;

int main()
{
	//fstream X(y); �]�@���ɮ��ܼơA���ɮצ�m�by
	//fstream �iinput,output
	//ifstream �u�iinput
	//ofstream �u�ioutput 
	
	fstream exc("inputtest.csv");
	//exc.open("C:\\Users\\cies_96035\\Desktop\\C++\\�m��\\inputtest.csv");
	//�P�_�ɮצ��S���}�Ҧ��\ 
	if(!exc.is_open())
	{ 
        cout << "CANNOT OPEN"<< endl;
    }
	char ch;
	while(!exc.eof()) 
	{ 
        exc.get(ch); 
        cout << ch; 
    } 
    exc.close();/*
    fstream exc;
	exc.open("C:\\Users\\cies_96035\\Desktop\\C++\\�m��\\inputtest.csv");
	if (!exc.is_open()) 
    {
        cout << "CANNOT OPEN"<< endl;
	}
	char ch;
	while(!exc.eof()) 
	{ 
        exc.get(ch); 
        cout << ch; 
    } 
    exc.close();*/
	return 0;
}

