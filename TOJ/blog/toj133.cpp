#include<iostream>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,Q;
    cin>>N;
    long long k[N],kSum[N+1]={0};//«eºó©M 
    for(int i=0;i<N;i++)
        cin>>k[i];
    
    for(int h=0;h<N;h++)
        kSum[h+1]=kSum[h]+k[h];
        
    cin>>Q;

    while(Q--)
    {
        int start,end;
        cin>>start>>end;
        if(start>end)swap(start,end);
        cout<<kSum[end]-kSum[start-1]<<endl;
    }
    return 0;
}
