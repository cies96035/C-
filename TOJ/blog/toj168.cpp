#include<iostream>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    while(cin>>N)
    {
        int n[N],ans=0,highest=0;//highest�����̰������
        
        for(int i=0;i<N;i++)cin>>n[i];
        
        while(N--)
        {
        	//�p�G�������e�������A�N�N��ݪ���A�������̰��Ȩì������� 
            if(n[N]>highest)
            {
                highest=n[N];
                ans++;
            }
		}
        cout<<ans<<'\n';
    }
    return 0;
}
