#include<iostream>
#include<algorithm> 
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		cout<<abs(((N*(567/9)+7492)*(235/47)-498)/10%10)<<'\n';
	}
	return 0;
}

