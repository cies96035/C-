#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int N;
    cin>>N;
    int num[N],sum=0;
    for(int i=0;i<N;i++)
    {
        cin>>num[i];
        sum+=num[i];
    }
    bool check[sum/2+1][2];
    
    memset(check,0,sizeof(check));
    check[0][0]=1;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=sum/2;j++)
        {    
            if(check[j][i%2]==1)
            {
            	if(j+num[i]<=sum/2)//避免RE 
            	{
                	check[j+num[i]][(i+1)%2]=1;
                	if(j+num[i]==sum/2)//達成條件結束，加快速度 
					{
						cout<<sum/2<<" "<<sum/2+sum%2<<endl;
						return 0;
					}
				}
                check[j][(i+1)%2]=1; 
            }
        }
    }
    
    int i=sum/2;
    while(i--)
    {
        if(check[i][N%2]==1)
        {
            cout<<i<<' '<<sum-i<<endl;
            break;
        }
    }
    
    return 0;
}
