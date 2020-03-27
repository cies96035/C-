#include<iostream>
using namespace std;

#define maxA 10000001
pair<int,int> prime[maxA];
//prime[i]，i.first紀錄i最大的質因數，i.second紀錄i第二大的質因數 i>=2

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0); 
    
    //預設1的最大質因數是1(實際上並不是)，但為了只有一個質因數的能順利顯示出1，要這樣預設 
    prime[1].first=1;
    int N,A;
    
    //篩法，把質因數丟進去質因數的倍數裡，只求最大的質因數     
    for(int i=2;i<maxA;i++)
    { 
        //得到最大質因數
        if(!prime[i].first)
            for(int j=i;j<maxA;j+=i)
                prime[j].first=i;
                
        /*
        得到第二大質因數 
        如果i為2*3*5^4，抓2*3*5^3的第二大 
        如果i為2*3*5^3，抓2*3*5^2的第二大...
        如果i為2*3*5，第二大為(2*3*5)/5的最大質因數也就是3 
        */ 
        N=i/prime[i].first;
        prime[i].second = (prime[N].first==prime[i].first) ? prime[N].second : prime[N].first;
    } 
    
    cin>>N;
    while(N--)
    {
        cin>>A;
        //直接輸出該數字前兩大的質因數即可 
        cout<<prime[A].second<<' '<<prime[A].first<<'\n';
    }
    return 0;
}
