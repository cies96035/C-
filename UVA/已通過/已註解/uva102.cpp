#include<iostream>
#include<algorithm>
using namespace std;


//bgc[第幾桶][哪個顏色(0:b,1:c,2:g(依字典序)] 
int bgc[3][3],index[3][6],sum,result,Min,Minid;
string ans[6];

void Init()
{
	int t[3]={0,1,2},j=0;
	char k[3]={'B','C','G'};
	do
	{
		for(int i=0;i<3;i++)
		{
			index[i][j]=t[i];
			ans[j]+=k[t[i]];	
		}
		j++;
	}
	while(next_permutation(t,t+3));
	
	return;
}

bool input()
{
	sum=0;
	//Brown>Green>Clear
	const int k[3]={0,2,1};
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(!(cin>>bgc[i][k[j]])) 
				return false;
			sum+=bgc[i][k[j]];
		} 
	return true;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Init();
	
	while(input())
	{
		Min=2e9;
		
		for(int i=0;i<6;i++)
		{
			result=sum;
			for(int j=0;j<3;j++)
				result-=bgc[j][index[j][i]];
			if(result<Min)
			{
				Min=result;
				Minid=i;
			}
		}
		cout<<ans[Minid]<<' '<<Min<<'\n';
	}
	return 0;
}

