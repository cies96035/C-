#include<iostream>
using namespace std;

string first,second;
bool turn=1;

inline bool cmp(char str[],int index)
{
	if(turn)
	{
		for(int i=2;i>=0;i--)
			if(str[index--%3]!=first[i])return 0;
	}
	else
	{
		for(int i=2;i>=0;i--)
			if(str[index--%3]!=second[i])return 0;
	}
	turn=!turn;
	for(int i=0;i<3;i++)str[++index%3]='*';
	return 1;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
	char str[3]={'*','*','*'},k,tmp;
	int sum=0,i=0,ans=0;
	while(i<6)
	{
		cin.get(k);
		if(i<3)
			first.append(1,k);
		else
			second.append(1,k);
		i++;
	}
	while(cin.get(k))
	{
		if(k>='0'&&k<='9')
			sum=sum*10+k-'0';
		else
		{
			if(sum>0)
			{
				tmp=str[(i-1)%3];
				for(int j=0;j<3&&sum>1;j++)
				{
					str[i%3]=tmp;
					if(cmp(str,i))ans++;
					i++;
					sum--;
				}
				sum=0;
			}
			if(k=='\n')break;
			else
			{
				str[i%3]=k;
				if(cmp(str,i))ans++;
				i++;
			}
		}
	}
	cout<<ans/2<<'\n';
	return 0;
}

