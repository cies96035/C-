#include<iostream>
using namespace std;

#define Max 955049953
#define Err 2147483647
typedef long long ll;

struct Num
{
	ll P,R;
};

Num Nummix(Num a,Num b)
{
	if(a.P<b.P)swap(a,b);
	if(!(a.P%b.P))return a;
	Num ans;
	
	
	//7 4 5 2
	ll x=a.P%b.P,//x=2=7%5
    y=b.R-a.R+(a.R/b.P)*b.P,//y=8=2-4+(4/2)*5
    f=(x-y)/b.P*b.P;//f=0=-4/5*5
    if(!f)f+=b.P;//f=5
    while(y%x||y<0)y+=f;//y=8
    ans.R=(y/x*a.P+a.R);//ans=32=8/2*7+4
    
    ans.P=a.P*b.P;
    if(ans.P>Err)ans.P=Err;
    
	return ans;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		Num input,ans;
		cin>>ans.P>>ans.R;
		while(--N)
		{
			cin>>input.P>>input.R;
			if(ans.R<Max)
			{
				if(input.R>input.P)input.R%=input.P;
				ans=Nummix(ans,input);
			}
		}
		cout<<(ans.R>=Max?-1:ans.R)<<'\n';
	}
	return 0;
}

