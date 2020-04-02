#include<iostream>
using namespace std;

int main(){
    //加速 
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    //用long long避免溢位 
    long long A,B,C,ans=1,k;
    
    cin>>A>>B>>C;
    k=A;
    
    //快速冪 
    while(B)
    {
        if(B%2==1)
            ans*=k; 
        B/=2;
        k*=k;
        ans%=C;//避免溢位 
        k%=C;//避免溢位 
    }
    //輸出答案 
    cout<<ans<<endl;
    return 0;
}
