#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);    
    cin.tie(0);  
    
    long long K,N,z,y,k;
    cin >> K;
    while(K--)
    {
        cin>>N;
        long long a[N+1];
        for(z=0;z<=N;z++)cin>>a[z];
        
        //相減 
        for(z=0,k=N;z<N;z++,k--)
            for(y=0;y<k;y++)
                a[y]=a[y+1]-a[y];
                
        cout<<a[0]<<endl;
    }
    return 0;
}
