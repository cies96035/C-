/*
有N個插頭和電器，以長度為L的0和1表示，只有完全相同時才能配對
你只有一種操作方法:把所有的插頭的某一個位元反轉
請問最少需要多少操作才能讓所有電器和插頭配對

輸入說明
第一行有一個整數T(T <= 50)，代表有幾組測資
每組測資的第一行有兩個整數N， L(N <= 1000,L <= 60)，代表有N個插頭和電器，並以長度為L的0和1表示

輸出說明
對每組測資輸出最少的操作數
若不能達成則輸出"IMPOSSIBLE"
輸出格式: "Case #i: num" or "Case #i: IMPOSSIBLE"
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<bitset>

//bitset:儲存1,0，.to_ulong()可以轉換成ull;
//暴力試看看
using namespace std;

typedef unsigned long long ull;

int T,N,L,MinAns;
ull two_pow[63]={1};//return pow(2,i);

void two_pow_Init()//建表
{
    for(int i=0;i<62;i++)
        two_pow[i+1]=two_pow[i]*2;
    return;
}

inline bool cmp(ull x,ull y,int pos)
{
    return (x-x%two_pow[pos+1])!=(y-y%two_pow[pos+1]);
}

void c(ull x[],ull device[],int i,int a)
{
    ull plug[N];
    memcpy(plug,x,sizeof(plug));

    int pos=L-i-1;//現在的位置

    //如果到最後一個位元，再檢查一次，如果還是一樣，更新答案
    if(i==L)
    {
        for(int j=0;j<N;j++)
            if(plug[j]!=device[j])return;
        MinAns=min(MinAns,a);
        return;
    }

    //現在位置的plug含0/1，以及device含0的數量
    int p_zero=0,d_zero=0,p_one;
    for(int j=0;j<N;j++)
    {
        if((plug[j]/two_pow[pos])%2==0)p_zero++;
        if((device[j]/two_pow[pos])%2==0)d_zero++;
    }
    p_one=N-p_zero;

    //如果device零的數量等同plug零的數量->檢查此位元以前的位置是否都相等
    //是->進入下一個位元，不進行反轉動作
    if(d_zero==p_zero)
    {
        int j=-1;
        while(++j<N)
            if(cmp(plug[j],device[j],pos))break;
        if(j==N)
            c(plug,device,i+1,a);
    }

    //如果device零的數量等同plug一的數量->進行反轉後再檢查此位元前的位置是否都相等
    //如果相等，則反轉動作加一 ，進入下一個位元
    if(d_zero==p_one)
    {
        //1.反轉
        for(int j=0;j<N;j++)((plug[j]/two_pow[pos])%2==0 ? plug[j]+=two_pow[pos] : plug[j]-=two_pow[pos] );
        //2.排序
        sort(plug,plug+N);
        //3.檢查
        for(int j=0;j<N;j++)
            if(cmp(plug[j],device[j],pos))return;
        c(plug,device,i+1,a+1);
    }

    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    two_pow_Init();

    cin>>T;

    for(int Case=0;Case<T;)
    {
        MinAns=100;//紀錄最小值，如果未被更新->Impossible
        cin>>N>>L;
        bitset<64> input;
        ull plug[N],device[N];

        for(int i=0;i<N;i++)
        {
            cin>>input;
            plug[i]=input.to_ulong();
        }

        for(int i=0;i<N;i++)
        {
            cin>>input;
            device[i]=input.to_ulong();
        }

        //排序以利檢查
        sort(plug,plug+N);
        sort(device,device+N);
        c(plug,device,0,0);

        cout<<"Case #"<<++Case<<": ";
        (MinAns!=100 ? cout<<MinAns<<'\n' : cout<<"IMPOSSIBLE\n");
    }
    return 0;
}
