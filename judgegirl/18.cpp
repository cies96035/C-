#include<iostream>
using namespace std;
 
int arr[200][200];
const int m[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main()
{
	int r,c;
	cin>>r>>c;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>arr[i][j];
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			const int num=arr[i][j];
			bool great=true;
			for(int k=0;k<4;k++)
			{
				int I=i+m[k][0],J=j+m[k][1];
				if(I>=0&&I<r&&J>=0&&J<c)
				{
					if(!(arr[I][J]<num))
					{
						great=false;
						break;
					}
				}
			}
			if(great)cout<<num<<endl;
		}
	return 0;
}
 
