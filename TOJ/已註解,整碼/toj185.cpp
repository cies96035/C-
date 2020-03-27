#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    while(cin>>T)
    {
        int A[T],B[T];
        long long sum=0;
        for(int h=0;h<T;h++)cin>>A[h];
        for(int h=0;h<T;h++)cin>>B[h];
        sort(A,A+T);
        sort(B,B+T);
        while(T--)
            sum+=A[T]*B[T];
        cout<<sum<<endl;
    }
    return 0;
}
