#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    while(cin>>N)
    {
        //預設第零筆資料為無限大，left_lower紀錄每根的左邊比該根低的共有幾個
        //tocmpid，要比較的id
        int n[N+1]={2147483647},left_lower[N+1]={0},tocmpid;
        
        //輸入
        for(int i=1;i<=N;i++)
			cin>>n[i];
        
        for(int i=1;i<=N;i++)
        {
            left_lower[i]=0;
        	tocmpid=i-1;
        	//如果沒被擋住，找出比該根小的有幾根 
            while(n[i]>n[tocmpid])
            {
                //如果比要比較的棒棒大，則吃掉他的答案和他本身
                left_lower[i]+=left_lower[tocmpid]+1;
                //是否能吃掉更前面的棒棒 
            	tocmpid-=left_lower[tocmpid]+1;
            }
        }
        
        //輸出 
        for(int i=1;i<N;i++)
        {
            cout<<left_lower[i];
            cout<<' ';
        }
        cout<<left_lower[N]<<endl;
    }
    return 0;
};
