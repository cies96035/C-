#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int N=1;N<=n;N++)
    {
        for(int M=1;M<=m;M++)
            cout<<N<<'*'<<M<<'='<<N*M<<' ';
        cout<<endl;
    }
    return 0;
}
