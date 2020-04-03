#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	long long c[3][3],sum=0,result[6],Min=2e9,index=0;
	string ans[6]={"BCG","BGC","CBG","CGB","GBC","GCB"};
	//c[第幾桶][哪個顏色(0:b,1:c,2:g(依字典序)] 
	while(
	cin>>c[0][0]>>c[0][2]>>c[0][1]>>c[1][0]>>
	c[1][2]>>c[1][1]>>c[2][0]>>c[2][2]>>c[2][1])
	{
		for(int i=0;i<3;i++)sum+=c[i][0]+c[i][1]+c[i][2];
		for(int i=0;i<3;i++)//012 021 102 120 201 210
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					if(i!=j&&j!=k&&k!=i)
					{
						result[index++]=sum-c[0][i]-c[1][j]-c[2][k];
					}
		for(int i=0;i<6;i++)
			if(result[i]<Min)
			{
				Min=result[i];
				index=i;
			}
		cout<<ans[index]<<' '<<Min<<endl;
		sum=index=0;
		Min=2e9;
	}
	return 0;
}

