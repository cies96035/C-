#include<iostream>
#include<fstream> 
using namespace std;

int main()
{
	ifstream exc;
	exc.open("C:\\Users\\cies_96035\\Desktop\\C++\\�m��\\inputtest.csv");
	char ch;
	while(!exc.eof()) { 
        exc.get(ch); 
        cout << ch; 
    } 
	return 0;
}

