#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int G,rs;
	string reverse;
	while(cin>>G)
	{
		if(G==0)break;
		cin>>reverse;
		rs=reverse.size();
		G=rs/G;
		for(int i=G-1;i<rs;i+=G)
			for(int j=0;j<G;j++)
				cout<<reverse[i-j];
		cout<<'\n';
	}
	return 0;
}

