#include<iostream>
using namespace std;

typedef long long ll;

struct Point
{
	ll x,y;
};

ll Abs(ll x)
{
	return x<0 ? -x : x;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	ll N,Q;
	while(cin>>N>>Q&&(N!=0||Q!=0))
	{ 
		Point point[N];
		for(int i=0;i<N;i++)
			cin>>point[i].x>>point[i].y;
		ll a,b,num1,num2;
		while(Q--)
		{
			cin>>a>>b;
			if(a>b)swap(a,b);
			
			num1=point[a].x*point[b].y-point[b].x*point[a].y;
			for(int i=0,end=N-b+a,index=b;i<end;i++,index++)
				num1+=point[index%N].x*point[(index+1)%N].y-point[(index+1)%N].x*point[index%N].y;
			
			num2=point[b].x*point[a].y-point[a].x*point[b].y;
			for(int i=0,end=b-a,index=a;i<end;i++,index++)
				num2+=point[index].x*point[index+1].y-point[index+1].x*point[index].y;
			
			cout<<min(Abs(num1),Abs(num2))*0.5<<'\n';
		}
	} 
	return 0;
}

