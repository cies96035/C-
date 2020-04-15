#include<iostream>
#include<fstream> 
using namespace std;

int main()
{
	fstream exc("inputtest.txt");
	char ch;
	string str="test";
	//fstream X(y)
	//fstream can input,output
	//ifstream input only
	//ofstream output only
	
	//check is the file open?
	if(!exc.is_open())
        cout << "CANNOT OPEN"<< endl;
    else
    {
		exc.seekg(5,ios::beg);
		//seekg tellg -> input
		//seelp tellp -> output
		cout<<exc.tellg();
		exc<<str<<endl;
	}
    exc.close();
	return 0;
}


