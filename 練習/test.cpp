#include <iostream>
#include <fstream>

using namespace std;

ifstream the_input("input.txt");
typedef long long ll;
#define MaxN 50
ll matrix[MaxN][MaxN];

int N;
ll ans=0;

void extend(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            matrix[i][j+n]=matrix[i][j];
    return;
}
int main()
{
    the_input>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            the_input>>matrix[i][j];
    extend(N);

    for(int i=0;i<N;i++)
    {
        int t=1;
        for(int j=0;j<N;j++)
            t*=matrix[j][i+j];
        ans+=t;
    }
    for(int i=0;i<N;i++)
    {
        int t=1;
        for(int j=0;j<N;j++)
            t*=matrix[N-1-j][i+j];
        ans-=t;
    }
    cout<<ans<<endl;
    return 0;
}
