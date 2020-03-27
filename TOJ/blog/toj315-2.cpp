#include<iostream>
using namespace std;

//將快速冪多個乘法加速的原理套用到加法，用來避免溢位 
long long mul(long long A,long long B,long long M)
{
    long long ans=0;
    while(B)
    {
        if(B%2==1)
        {
            ans=ans+A;
	        if(ans>=M)//優化 
	        	ans%=M;
		}
        A*=2;
        if(A>=M)//優化 
	        A%=M;
        B/=2;
    }
    return ans;
}

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0);
    
    long long A,B,M,ans=1,T;
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
            B/=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
