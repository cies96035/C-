#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int T;
    //�h���� 
    while(cin>>T)
    {
    	//�w�]�Ĥ@����Ƭ��L���j 
        int n[T+1]={2147483647},N[T+1]={0};
        
        //��J 
        for(int m=1;m<=T;m++)cin>>n[m];
        
        for(int i=1;i<=T;i++)
        {
        	if(n[i]>n[i-1])
        	{
        		int k=i-1;
        		while(n[i]>n[k])
        		{
        			N[i]+=N[k]+1;
        			k-=N[k]+1;
				}
			}
			else
			{
				N[i]=0;
			}
		}
		//��X 
		for(int i=1;i<=T;i++)
		{
			cout<<N[i];
			if(i!=T)cout<<' ';
			else cout<<'\n';
		}
    }
    return 0;
};
