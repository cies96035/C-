#include<iostream>
using namespace std;

//true Ans version

int N;

struct Roman
{
	int i,v,x,l,c;
	void add(int n,int k)
	{
		if(k==0)
			c+=n;
		else if(k==2)
			l+=n;
		else if(k==4)
			x+=n;
		else if(k==6)
			v+=n;
		else if(k==8)
			i+=n;
		return;
	}
	Roman operator + (const Roman &x)
	{
		Roman tmp;
		tmp.c=x.c+this->c;
		tmp.l=x.l+this->l;
		tmp.x=x.x+this->x;
		tmp.v=x.v+this->v;
		tmp.i=x.i+this->i;
		return tmp;
	}
	void Print()
	{
		cout<<i<<" i, "<<v<<" v, "<<	x<<" x, "<<l<<" l, "<<c<<" c\n";
		return;
	}
}
roman[101],roman_sum[101];

const Roman sp[4]={{0,0,1,0,1},{0,0,1,1,0},{1,0,1,0,0},{1,1,0,0,0}};//90,40,9,4
const int V[9]={100,90,50,40,10,9,5,4,1};

void Init()
{
	int n,v=0;
	for(int i=1;i<=100;i++,v=0)
	{
		n=i;
		while(n)
		{
			if(n>=V[v])
			{
				if(v%2)
				{
					roman[i]=roman[i]+sp[v/2];
					n-=V[v];
				}
				else
				{
					roman[i].add(n/V[v],v);
					n%=V[v];
				}
			}
			v++;
		}
		roman_sum[i]=roman_sum[i-1]+roman[i];
	}
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Init();
	
	while(cin>>N&&N)
	{
		//true Ans
		cout<<N<<": ";
		roman_sum[N].Print();
	}
	
	return 0;
}

