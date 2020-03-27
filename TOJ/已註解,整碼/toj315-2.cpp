#include<iostream>
using namespace std;

//�N�ֳt���h�ӭ��k�[�t����z�M�Ψ�[�k�A�Ψ��קK���� 
long long mul(long long A,long long B,long long M)
{
    long long ans=0;
    while(B)
    {
        if(B%2==1)
        {
            ans=ans+A;
	        if(ans>=M)//�u�� 
	        	ans%=M;
		}
        A*=2;
        if(A>=M)//�u�� 
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
