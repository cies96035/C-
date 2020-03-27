#include<iostream>
using namespace std;
//£{£¡ÃD¥Ø 
int n=0;
string M;

int main()
{	
	cin>>M;
	for(int i=0;i<M.size();i++)
		n+=M[i];
	if(n%3)
		cout<<"Sorry..."<<endl;
	else
		cout<<"You are lucky."<<endl;
	return 0;
}
