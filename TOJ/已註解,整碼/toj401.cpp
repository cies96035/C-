//看起來很麻煩而已，其實還好
//搞好數學對程設真的很重要... 
/*
f的值會直接讓ax^5+bx^4+cx^3+dx^2+ex+f的圖形上下移動
所以我們計算一個點(x,y),將x帶進去,
儲存一個b值要加多少才會等於y
將第K小的b輸出就是答案...

嘛...實作不難，
但就是...數學嘛... 
*/ 
/*
小技巧(省一半左右時間 
ax^5+bx^4+cx^3+dx^2+ex+d
==
(((((0*x+a)*x+b)*x+c)*x+d)*x+e)+d

這個很重要，像是給你一個字串S，
a帶S[0]-'0'，b帶S[1]-'0'...，X帶10，
就能將字串輕鬆轉換成數字 
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct water
{
    int x,y;
};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0); 
    
    int K,a[5],N;
    cin>>K;
    for(int i=0;i<5;i++)cin>>a[i];
    cin>>N;
    water W[N];
    int b[N];
    for(int i=0;i<N;i++)
    {
        cin>>W[i].x>>W[i].y;
    }
    for(int i=0;i<N;i++)
    {
        int k=W[i].x,ans=0;
        for(int j=0;j<5;j++)
        {
            ans=ans*k+a[j];
        }
        ans*=k;
        b[i]=W[i].y-ans;
    }
    sort(b,b+N);
    cout<<b[N-K]<<endl;
    return 0;
}
