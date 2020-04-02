//注意一下mod位置，避免超出long long範圍
#include<iostream>
using namespace std;
int main()
{
    long long a,m,b,n;
    char d;
    cin>>a>>m>>b;
    while(m--)
    {
        cin>>n>>d;
        a*=n;
        a%=b;
    }
    cout<<a<<endl;
    return 0;
}
