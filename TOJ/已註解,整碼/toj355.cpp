#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,K,second=0,biggest=0;
    cin>>N>>K;//這個K用不到 
    while(N--)
    {
        cin>>K;
        if(K>biggest)swap(K,biggest);
        if(K>second)swap(K,second);
        //每次迴圈，儲存最大和第二大的值 
    }
    cout<<second<<endl;
    //輸出最後的第二大值 
    return 0;
}
