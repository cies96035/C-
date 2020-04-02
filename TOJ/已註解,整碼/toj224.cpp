#include<iostream>
using namespace std;
int main()
{
    int a,b;    
    //如果題目給30~40，遠超過int範圍，要用long long
    //乘法的單位元素為1 
    long long ans=1;
    cin>>a>>b;
    if(a>b)swap(a,b);//避免出錯 
    //從a乘到b 
    while(a<=b)
    {
        ans*=a;
        a++;
    }
    //輸出答案 
    cout<<ans<<endl;
    return 0;
}
