//想一下可以知道只要求2*1的，最佳解必出現在2*1
//吃了一WA，想一下還有可能出現在3*1 = = 
//越來越不確定了...怕... 

#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		int tasty[n][m],max2=0,max3=0,num;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>tasty[i][j];
				if(j>0)
				{
					num=tasty[i][j]+tasty[i][j-1];
					if(max2<num)max2=num;
					if(j>1)
					{
						num+=tasty[i][j-2];
						if(max3<num)max3=num;
					}
				}
				if(i>0)
				{
					num=tasty[i][j]+tasty[i-1][j];
					if(max2<num)max2=num;
					if(i>1)
					{
						num+=tasty[i-2][j];
						if(max3<num)max3=num;
					}
				}
			}
			
				
		if(max2*3>max3*2)
			cout<<(max2%2?max2:max2/2)<<'/'<<(max2%2?2:1)<<'\n';
		else
			cout<<(max3%3?max3:max3/3)<<'/'<<(max3%3?3:1)<<'\n';
			
	} 
	return 0;
}

