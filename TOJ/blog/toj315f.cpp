//失敗 

#include<iostream>
using namespace std;

#define beERR 2147483647

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
            {
            	/*
				將a乘b(本來會溢位) 
				拆成a*c+a*c+a*c.....T個  +a*d
				變成a*c(modM)*T+a*d
				
				c:a*c之後modM可以剛好變很小的數 
				d:c*T+d=b
				*/ 
				//a*c(modM)*T還是會爆掉 
				long long c=(M/ans+1),T=(A/c),d=(A-c*T);
            	ans=ans*c%M*T%M+ans*d;
            	ans%=M;
			}
			long long c=(M/A+1),T=(A/c),d=(A-c*T);
            A=A*c%M*T%M+A*d;
            A%=M;
            B/=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
