#include<iostream>
#include<algorithm>//sort要用到 
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n,t,K;
    cin>>n;
    int X[n];
    for(int i=0;i<n;i++)cin>>X[i];
    
    sort(X,X+n);//排序過才能用lowerbound
    
    cin>>t;
    while(t--)
    {
        cin>>K;
        if(K<X[0])cout<<"no "<<X[0]<<endl;//如果比最小值小 
        else if(K>X[n-1])cout<<X[n-1]<<" no"<<endl;//如果比最大值大 
        else if(*lower_bound(X,X+n,K)==K)cout<<K<<endl;//如果剛好有這個值 
        else cout<<*(lower_bound(X,X+n,K)-1)<<" "<<*lower_bound(X,X+n,K)<<endl;
        //輸出第一個大於這個值的前一個，也就是<這個值的最大值，和第一個大於這個值的 
    }
    return 0;
}
