#include<iostream>
#include<algorithm>//sort�n�Ψ� 
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n,t,K;
    cin>>n;
    int X[n];
    for(int i=0;i<n;i++)cin>>X[i];
    
    sort(X,X+n);//�ƧǹL�~���lowerbound
    
    cin>>t;
    while(t--)
    {
        cin>>K;
        if(K<X[0])cout<<"no "<<X[0]<<endl;//�p�G��̤p�Ȥp 
        else if(K>X[n-1])cout<<X[n-1]<<" no"<<endl;//�p�G��̤j�Ȥj 
        else if(*lower_bound(X,X+n,K)==K)cout<<K<<endl;//�p�G��n���o�ӭ� 
        else cout<<*(lower_bound(X,X+n,K)-1)<<" "<<*lower_bound(X,X+n,K)<<endl;
        //��X�Ĥ@�Ӥj��o�ӭȪ��e�@�ӡA�]�N�O<�o�ӭȪ��̤j�ȡA�M�Ĥ@�Ӥj��o�ӭȪ� 
    }
    return 0;
}
