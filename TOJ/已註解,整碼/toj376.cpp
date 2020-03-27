//此版本不能AC，儲存的方式修改倒是有機會AC 
#include<iostream>
using namespace std;

const int mod =1000000009;

//紀錄費氏數列的陣列，預設為0(沒紀錄過)
//主要目的是用來加快遞迴速度，如果已經得知第i項的值，遞迴可以不用重複做 
//不然遞迴會變得，超級慢!!!! 
long long f[100000000];//題目要求2^63-1，沒注意到...沒辦法開那麼大.... 

//求得第幾項費式數列的遞迴函式
long long F(long long n)
{
    //預設1,2項為1 
    if(n<=2)
        return f[n]=1;

    //如果已經有紀錄，直接回傳該紀錄
    if (f[n])
        return f[n];
        
    long long k = (n%2+n)/2;

    //就...照做吧，請參閱維基百科>費氏數列>矩陣...
    f[n]=(n%2)?(F(k)*F(k)+F(k-1)*F(k-1)):(2*F(k-1)+F(k))*F(k);
    if(f[n]>=mod)f[n]%=mod;
    return f[n];
}

int main() {
    int i;
    while(cin>>i) 
    {
        cout<<F(i+2)-1<<endl;
    }
    return 0;
}
