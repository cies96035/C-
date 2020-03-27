#include<iostream>
using namespace std;

//類似埃氏篩法，空間不知道會不會爆 =A=

const int maxN=10000;
bool cantsee[maxN+1][maxN+1];
int record[maxN+1];

int main()
{
	//for(int i=2;i<=maxN;i++)cantsee[i][i]=1;
	for(int i=1;i<=maxN;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(cantsee[i][j]==0)
			{
				for(int ii=i+i,jj=j+j;ii<=maxN;ii+=i,jj+=j)
				{
					if(!cantsee[ii][jj])
						cantsee[ii][jj]=1;
				}
				cout<<i<<j<<endl;
			}
		}
	}
	
	return 0;
}

