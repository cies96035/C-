#include<iostream>
using namespace std;
int main()
{
    //cin加速 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    
    //宣告變數，f陣列皆為0; 
    int S,W,Q,k,A[100001];
    bool f[200001]={0},s[100001]={0};
        
    //輸入心情指數 
    cin>>S;
    for(int i=0;i<S;i++)
    {
        cin>>k;
        if(s[k])//如果題目有大量相同數值，可降低處理心情指數速度 
        {
            S--;
            i--;
            continue;
        }
        s[k]=1;
        A[i]=k;
        for(int j=i;j>=0;j--)
            if(!f[k+A[j]])
                f[k+A[j]]=1;
    }

    //判斷並輸出 
    cin>>Q;
    while(Q--)
    {
        cin>>W;
        if(f[W])cout<<"yes\n";
        else cout<<"no\n";
    }
        
    
    return 0;
}
