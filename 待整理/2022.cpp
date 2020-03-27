#include<iostream>
#include<cstring>
using namespace std;

int const Max=30;
int N,M,arr[Max][Max];
int ca[Max][Max][Max][Max];

int c1(int k,int i,int j)//返回第k個直排，i到j個值 
{
	int s=0;
	for(;i<=j;i++)
		if(arr[i][k])s++;
	return min(s,N-s);//一個值排有N個元素 
}
int c2(int k,int i,int j)//返回第k個橫排，i到j個值
{
	int s=0;
	for(;i<=j;i++)
		if(arr[k][i])s++;
	return min(s,M-s);
} 

int D(int a,int b,int c,int d)
{
	int D1,D2,D3,D4,V;
	if(ca[a][b][c][d]!=-1)return ca[a][b][c][d];//避免TLE，有做過的話可以避免重做 
	if(a==c||b==d)return 0;
	if(a<c)
	{
		D1=D(a+1,b,c,d)+c1(a,b,d);
		D2=D(a,b,c-1,d)+c1(c,b,d);
		V=min(D1,D2);
	}
	if(b<d)
	{
		D3=D(a,b+1,c,d)+c2(b,a,c);
		D4=D(a,b,c,d-1)+c2(d,a,c);
		V=min(V,min(D3,D4));
	}
	return ca[a][b][c][d]=V;
}
int main()
{
	memset(ca,-1,sizeof(ca));
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>arr[i][j];
	cout<<D(0,0,M-1,N-1)<<'\n';
	return 0;
}
/*
4 5
1 1 1 0 1
0 1 0 1 1
0 0 0 0 0
0 0 0 1 0

3 5
0 0 0 1 0
1 0 1 1 1
0 0 0 1 0
*/
