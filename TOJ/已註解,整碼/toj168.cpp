#include<iostream>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    while(cin>>N)
    {
        int n[N],ans=0,highest=0;//highest紀錄最高的桿杆
        
        for(int i=0;i<N;i++)cin>>n[i];
        
        while(N--)
        {
        	//如果此桿杆比前面的高，就代表看的到，紀錄為最高值並紀錄次數 
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
