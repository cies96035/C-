#include<iostream>
using namespace std;

int main()
{
	int t;
	char k;
	cin>>t;
	while(t--)
	{
		int num,sum=0;
		for(int i=0;i<3;i++)
		{
			cin>>k;
			sum=(k-'A')+sum*26;
		}
		cin>>k>>num;
		if(abs(sum-num)<=100)
			cout<<"nice"<<endl;
		else
			cout<<"not nice"<<endl;
	}
	return 0;
}

