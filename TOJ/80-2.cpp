//靠北難題= = 

#include<iostream>
using namespace std;
const int N=1001;
int num[N][N];//a~b時差多少分 
int A[N];
int choose(int n1,int n2)
{
    if(num[n1][n2])return num[n1][n2];
    if(n2==n1)return num[n1][n2]=A[n1];
    return num[n1][n2]=max(A[n2]-choose(n1,n2-1),A[n1]-choose(n1+1,n2));
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        sum+=A[i]; 
    }
    choose(0,--n);
    cout<<(sum+num[0][n])/2<<' '<<(sum-num[0][n])/2<<'\n';
    return 0;
}
