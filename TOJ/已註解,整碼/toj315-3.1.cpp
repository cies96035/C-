#include<iostream>
using namespace std;

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0);
    
    long long T,a,B,M,coutans;
    __int128 A,ans;
    
    cin>>T; 
    while(T--)
    {
        cin>>a>>B>>M;
        A=a;
        ans=1;
        while(B)
        {
            if(B%2==1)
            {
                ans*=A;
				if(ans>=M)
					ans%=M; 
			}
            A*=A;
			if(A>=M)
				A%=M; 
            B/=2;
        }
        coutans=ans;
        cout<<coutans<<endl;
    }
    return 0;
}
