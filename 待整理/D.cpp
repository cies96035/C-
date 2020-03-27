#include<iostream>
#include<algorithm>
#include<cstring>
#include<bitset> 
using namespace std;

typedef unsigned long long ull;

int N,L,Cmp,ans;
ull two_pow[63]={1};

inline bool cmp(ull x,ull y)
{
	return (x-x%two_pow[Cmp+1])!=(y-y%two_pow[Cmp+1]);
}

void two_pow_Init()
{
	for(int i=0;i<62;i++)
		two_pow[i+1]=two_pow[i]*2;
	return;
}

void c(ull x[],ull device[],int i,int a)
{	
	ull plug[N];
	memcpy(plug,x,sizeof(plug));
	
	Cmp=L-i-1;
	
	if(i==L)
	{
		for(int j=0;j<N;j++)
			if(cmp(plug[j],device[j]))return;
		ans=min(ans,a);
		return;
	}
	
	int p_zero=0,d_zero=0,p_one;
	
	for(int j=0;j<N;j++)
	{
		if((plug[j]/two_pow[Cmp])%2==0)p_zero++;
		if((device[j]/two_pow[Cmp])%2==0)d_zero++; 
	}
	
	p_one=N-p_zero;
	
	if(d_zero==p_zero)
	{
		int j=-1;
		while(++j<N)
			if(cmp(plug[j],device[j]))break;
		if(j==N)
			c(plug,device,i+1,a);
	}
	
	if(d_zero==p_one)
	{
		Cmp=L-i-1;
		for(int j=0;j<N;j++)((plug[j]/two_pow[Cmp])%2==0 ? plug[j]+=two_pow[Cmp] : plug[j]-=two_pow[Cmp] );
		sort(plug,plug+N);
		for(int j=0;j<N;j++)
			if(cmp(plug[j],device[j]))return;
		c(plug,device,i+1,a+1);
	}
	
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	two_pow_Init();
	
	int T;
	cin>>T;
	
	for(int Case=0;Case<T;)
	{
		ans=100;
		cin>>N>>L;
		bitset<64> input;
		ull plug[N],device[N];
		
		for(int i=0;i<N;i++)
		{
			cin>>input;
			plug[i]=input.to_ulong();
		}
		
		for(int i=0;i<N;i++)
		{
			cin>>input;
			device[i]=input.to_ulong();
		}
		
		sort(plug,plug+N);
		sort(device,device+N);
		c(plug,device,0,0);
		
		cout<<"Case #"<<++Case<<": ";
		(ans!=100 ? cout<<ans<<'\n' : cout<<"IMPOSSIBLE\n");
	}
	return 0;
}

