#include<iostream>
#include<algorithm> 
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,M,ask;
    
    cin>>N;
    int A[N];
    for(int h=0;h<N;h++)cin>>A[h];
    
    sort(A,A+N);
    
    cin>>M;
    while(M--)
    {
        cin>>ask;
        cout<<upper_bound(A,A+N,ask)-lower_bound(A,A+N,ask)<<'\n';
    }
    return 0;
}
