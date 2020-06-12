#include<iostream>
using namespace std;

typedef long double ld;
#define iszero(a) (-0.000001<a&&a<0.000001)

const int maxN=14;
ld arr[maxN][maxN];
int N,T;

void Swap(int a,int b)
{
	for(int i=0;i<N;i++)
		swap(arr[a][i],arr[b][i]);
}
void add(int a,int b,ld k)
{
	for(int i=0;i<N;i++)
		arr[a][i]+=arr[b][i]*k;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				cin>>arr[i][j];
		bool NO=0;
		for(int i=0;i<N;i++)
		{
			if(iszero(arr[i][i]))
			{
				for(int j=i;j<N;j++)
					if(!iszero(arr[j][i]))
					{
						Swap(i,j);
						break;
					}
				if(iszero(arr[i][i]))
				{
					NO=1;
					break;
				}
			}
			for(int j=i+1;j<N;j++)
				add(j,i,-(arr[j][i]/arr[i][i]));
		}
        if(NO)cout<<"NO\n";
        else cout<<"YES\n";
	}
	return 0;
}

