#include<iostream>
using namespace std;

int main()
{
	int t,ans[10]={76,16,56,96,36,76,16,56,96,36};
	cin>>t;
	while(t--)
	{
		string num;
		cin>>num;
		if(num=="0")
			cout<<'1'<<endl;
		else if(num=="1")
			cout<<"66"<<endl;
		else
			cout<<ans[num[num.size()-1]-'0']<<endl;
	}
	return 0;
}

