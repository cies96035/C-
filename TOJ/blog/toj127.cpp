#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	cin.ignore();
	char D;
	while(cin.get(D))
	{
		if(D=='\n')break;
		D=(D-'A'-t+26)%26+'A';//+26¬OÁ×§K­t¼Æ
		cout<<D;
	}
	cout<<endl;
	return 0;
}

