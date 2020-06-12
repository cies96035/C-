#include<iostream>
using namespace std;

//a little slow...

#define MaxN 5010
int N;

struct BIGNUM
{
	string num;
	BIGNUM operator + (const BIGNUM &x)
	{
		int Max=max(this->num.size(),x.num.size());
		bool carry=0;
		BIGNUM B;
		for(int i=0;i<Max;i++)
		{
			if(i<this->num.size()&&i<x.num.size())
				B.num+=this->num[i]+x.num[i]-'0'+carry;
			else if(i<this->num.size())
				B.num+=this->num[i]+carry;
			else
				B.num+=x.num[i]+carry;
			carry=0;
			if(B.num[i]>'9')
			{
				B.num[i]-=10;
				carry=1;
			}
		}
		if(carry)
			B.num+='1';
		return B;
	}
	void print(int n)
	{
		cout<<"The Fibonacci number for "<<n<<" is ";
		for(int i=num.size()-1;i>=0;i--)
			cout<<num[i];
		cout<<'\n';
	}
}F[MaxN];

void Init()
{
	F[0].num="0";
	F[1].num="1";
	for(int i=2;i<MaxN;i++)
		F[i]=F[i-1]+F[i-2];
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	Init();
	
	while(cin>>N)
		F[N].print(N);
	return 0;
}

