#include <iostream>
#include <fstream>

using namespace std;

ifstream the_input("input.txt");
typedef long long ll;
#define MaxN 50
#define roll(x,y) matrix[x][(y+n-k)%(n)+k]
int N;
ll matrix[MaxN][MaxN];

#define addminus(i) ((i%2) ? -1 : 1)

void print(int n,int x,int y)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<matrix[i+x][j+y]<<' ';
        cout<<endl;
    }
    return;
}
ll f(int n,int x,int y,int k)
{
    for(int i=N;i>n;i--)
        cout<<"   ";
    cout<<"level:"<<n<<" x:"<<y<<" y:"<<x<<k<<endl;
    if(n==2)
    {
        //ad-bc
        //cout<<roll(x,y)<<roll(x+1,y+1)<<endl;
        return
        roll(x,y)*roll(x+1,y+1)-
        roll(x,y+1)*roll(x+1,y);
    }
    ll value=0;

    for(int i=0;i<n;i++)
    {
        int tmp=f(n-1,x+1,(y+i+1)%N,y);
        value+=addminus(i)*matrix[x][y+i]*tmp;
        for(int k=N;k>=n;k--)
            cout<<"   ";
        cout<<addminus(i)<<'*'<<matrix[x][y+i]<<'*'<<tmp<<endl;
    }
    return value;
}

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
    cout<<f(N,0,0,0)<<endl;
    return 0;
}
