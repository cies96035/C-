#include<iostream>
using namespace std;

int main()
{
	int N;
	int k=1;
	cin>>N;
	for(int i=0;i<N;i++)//N*N®æ 
	{
		for(int j=0;j<N;j++)
		{
			if(k%2)cout<<'*';
			else cout<<'-';
			k++;
		}
		if(N%2==0)k++;
		cout<<endl;
	}
	if(N==0)cout<<"Nothing"<<endl;
	return 0;
}

