#include<iostream>
using namespace std;

string tab="  ";
void couttab(int n)
{
	while(n--)
		cout<<tab;
}
int main()
{
	int M,n;
	cin>>M;
	while(M--)
	{
		cin>>n;
		cout<<"program sort(input,output);\nvar\n";
		cout<<'a';
		for(int i=1;i<n;i++)
			cout<<','<<(char)('a'+i);
		cout<<" : integer;\nbegin\n  readln(";
		cout<<'a';
		for(int i=1;i<n;i++)
			cout<<','<<(char)('a'+i);
		cout<<");\n";
	}
	return 0;
}

