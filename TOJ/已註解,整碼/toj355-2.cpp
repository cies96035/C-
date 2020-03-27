#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin>>N>>K;
    int num[N];
    
    for(int n=0;n<N;n++)
        cin>>num[n];

    sort(num,num+N);
    
    cout<<num[N-2]<<endl;
    return 0;
}
