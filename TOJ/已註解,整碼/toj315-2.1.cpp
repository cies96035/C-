#include<iostream>
using namespace std;

const long long ERR = 9e18;//ull上限約為 1.8e19 ，當超過上限一半時要mod避免出錯 

//將快速冪多個乘法加速的原理套用到加法，用來避免溢位 
inline unsigned long long mul(unsigned long long A,unsigned long long B,unsigned long long M)
{
    unsigned long long ans=0;
    if(B>A)swap(B,A);//優化 
    while(B)
    {
        if(B%2==1)
        {
            ans=ans+A;
            if(ans>ERR)//優化加速 
                ans%=M;
        }
        A*=2;
        if(A>ERR)//優化加速 
            A%=M;
        B/=2;
    }
    return ans%M;
}

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0);
    
    unsigned long long A,B,M,ans=1,T;
    cin>>T; 
    while(T--)
    {
        cin>>A>>B>>M;
        ans=1;
        while(B)
        {
            if(B%2==1)
                ans=mul(ans,A,M); 
            A=mul(A,A,M);
            if(!A)//優化 
            {
                ans=0;
                break;
            }
            B/=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
