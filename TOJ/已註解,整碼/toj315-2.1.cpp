#include<iostream>
using namespace std;

const long long ERR = 9e18;//ull�W������ 1.8e19 �A��W�L�W���@�b�ɭnmod�קK�X�� 

//�N�ֳt���h�ӭ��k�[�t����z�M�Ψ�[�k�A�Ψ��קK���� 
inline unsigned long long mul(unsigned long long A,unsigned long long B,unsigned long long M)
{
    unsigned long long ans=0;
    if(B>A)swap(B,A);//�u�� 
    while(B)
    {
        if(B%2==1)
        {
            ans=ans+A;
            if(ans>ERR)//�u�ƥ[�t 
                ans%=M;
        }
        A*=2;
        if(A>ERR)//�u�ƥ[�t 
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
            if(!A)//�u�� 
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
