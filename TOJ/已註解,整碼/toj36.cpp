#include<iostream>
using namespace std;

int main(){
    //�[�t 
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    //��long long�קK���� 
    long long A,B,C,ans=1,k;
    
    cin>>A>>B>>C;
    k=A;
    
    //�ֳt�� 
    while(B)
    {
        if(B%2==1)
            ans*=k; 
        B/=2;
        k*=k;
        ans%=C;//�קK���� 
        k%=C;//�קK���� 
    }
    //��X���� 
    cout<<ans<<endl;
    return 0;
}
