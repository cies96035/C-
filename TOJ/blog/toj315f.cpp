//���� 

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
				�Na��b(���ӷ|����) 
				�a*c+a*c+a*c.....T��  +a*d
				�ܦ�a*c(modM)*T+a*d
				
				c:a*c����modM�i�H��n�ܫܤp���� 
				d:c*T+d=b
				*/ 
				//a*c(modM)*T�٬O�|�z�� 
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
