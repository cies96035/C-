#include<iostream>
using namespace std;

int N,B,H,W;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	while(cin>>N>>B>>H>>W)
	{
		int Min=B+1,p,a;
		while(H--)
		{
			cin>>p;
			for(int i=0;i<W;i++)
			{
				cin>>a;
				if(a>=N&&p*N<Min)
					Min=p*N;
			}
		}
		if(Min<=B)
			cout<<Min<<'\n';
		else
			cout<<"stay home\n";
	}
	return 0;
}

