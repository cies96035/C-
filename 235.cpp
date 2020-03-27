#include<iostream>
#include<vector>
using namespace std;

const int N=46341;
vector<int> P;
bool isprime[N];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for(int i=2;i<=N;i++)
	{
		if(!isprime[i])
		{
			P.push_back(i*i);
			for(int j=i+i;j<=N;j+=i)
				isprime[j]=1;
		}
	}
	
	int T;
	cin>>T;
	while(T--)
	{
		int i,j,index=0,sum;
		cin>>i>>j;
		sum=j-i+1;
		bool PP[j-i+1];
		while(i<=j)
		{
			if(!PP[index])
			{
				for(int k=0;k<P.size();k++)
				{
					if(!(i%P[k]))
					{
						for(int kk=i+P[k];kk<=j;kk+=P[k])
						{
							PP[index+kk-i]=1;
							sum--;
						}
						sum--;
					}
				}
			}
			i++;
			index++;
		}
		cout<<sum<<'\n';
	}
	return 0;
}

