#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int num[N];
    for(int i=0;i<N;i++)cin>>num[i];
    for(int i=N-1;i>=0;i--)cout<<num[i]<<endl;
    return 0;
}
