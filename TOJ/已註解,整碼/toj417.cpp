#include<iostream>
using namespace std;

int main()
{
	string n;
	cin>>n;
	int ns=n.size();
	bool f=1;
	while(ns)
	{
		ns--;
		if(n[ns]=='2'||n[ns]=='3'||n[ns]=='5'||n[ns]=='7');
		else 
		{
			f=0;
			break;
		}
	}
	if(f) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

