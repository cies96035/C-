#include<iostream>
using namespace std;


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		int num,sum=0;
		cin>>num;
		for(int i=1;i<num;i++)
			if(!(num%i))sum+=i;
		if(num>sum) cout<<"deficient"<<endl;
		else if(num==sum) cout<<"perfect"<<endl;
		else cout<<"abundant"<<endl;
	}
	return 0;
}

