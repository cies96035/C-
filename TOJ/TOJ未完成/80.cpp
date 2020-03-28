//¾a¥_ÃøÃD= = 

#include<iostream>
using namespace std;
const int N=1001;
#define zero 123456789
#define iszero(k) (k==zero?0:k)
int num[N][N];
int choose(int n1,int n2)
{
	if(num[n1][n2])return num[n1][n2];
	num[n1][n2]=max(
	iszero(num[n2][n2])-iszero(choose(n1,n2-1)),
	iszero(num[n1][n1])-iszero(choose(n1+1,n2)));
	if(!num[n1][n2])num[n1][n2]=zero;
	return num[n1][n2];
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n,sum=0,A;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A;
		num[i][i]=(A==0?zero:A);
		sum+=A; 
	}
	choose(0,--n);
	cout<<(sum+iszero(num[0][n]))/2<<' '<<(sum-iszero(num[0][n]))/2<<'\n';
	return 0;
}
