#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Nums
{
	int turn;
	string num;
	Nums(int a){turn=a;}
};

bool cmp(Nums x,Nums y)
{
	return x.turn<y.turn;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int	t;
	cin>>t;
	while(t--)
	{
		char k;
		int turn=0,arrsize=0;
		string nums;
		vector<Nums> arr;
		
		cin.get();
		cin.get();
		while(cin.get(k))
		{
			if(k>='0'&&k<='9')
				turn=turn*10+k-'0';
			else
			{
				arr.emplace_back(turn);
				if(turn>arrsize)arrsize=turn;
				turn=0;
				if(k=='\n')break;
			}
		}
		
		for(int i=0;i<arrsize;i++)
		{
			cin>>nums;
			arr[i].num=nums;
		}
		
		sort(&arr[0],&arr[0]+arrsize,cmp);
		
		for(int i=0;i<arrsize;i++)
			cout<<arr[i].num<<'\n';
		if(t)cout<<'\n';
		
		 
	}
	return 0;
}

