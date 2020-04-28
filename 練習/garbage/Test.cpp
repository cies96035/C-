#include<iostream>
#include<fstream> 
using namespace std;

int main()
{
	//fstream X(y); 設一個檔案變數，該檔案位置在y
	//fstream 可input,output
	//ifstream 只可input
	//ofstream 只可output 
	
	fstream exc("inputtest.csv");
	//exc.open("C:\\Users\\cies_96035\\Desktop\\C++\\練習\\inputtest.csv");
	//判斷檔案有沒有開啟成功 
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
	exc.open("C:\\Users\\cies_96035\\Desktop\\C++\\練習\\inputtest.csv");
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

