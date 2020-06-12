#include<iostream>
using namespace std;

typedef long long ll;
const int maxN=14;
ll arr[maxN][maxN];
int N;

void print()
{
	
		for(int k=0;k<N;k++)
		{
			for(int f=0;f<N;f++)
			{
				cout<<arr[k][f]<<' ';
			}
			cout<<endl;
		}
}
ll gcd(ll a,ll b)
{
	while((a%=b)&&(b%=a));
	return a+b;
}
ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

void mul(int k,int a)
{
	for(int i=0;i<N;i++)
		arr[k][i]*=a;
}
void S(int a,int b)
{
	for(int i=0;i<N;i++)
		swap(arr[a][i],arr[b][i]);
}
void add(int a,int b,int k)
{
	for(int i=0;i<N;i++)
		arr[a][i]+=arr[b][i]*k;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				cin>>arr[i][j];
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				ll a=arr[i][i],b=arr[j][i];
				if(!a||!b)continue;
				mul(i,lcm(a,b)/a);
				mul(j,lcm(a,b)/b);
				add(j,i,-1);
			}
		}
		bool NO=0;
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
				if(arr[j][i])NO=1;
			if(!arr[i][i])NO=1;
		}
		if(NO)cout<<"NO\n"<<flush;
		else cout<<"YES\n"<<flush;
	}
	return 0;
}

