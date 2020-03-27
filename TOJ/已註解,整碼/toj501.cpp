#include<iostream>
using namespace std;

const int mxN=100010;

int h[mxN]={1},N,m[mxN],mx=1;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>m[i];
	
	for(int i=1,end=2*N-1;i<end;i++)//因為繞圈，執行兩倍長 
	{
		if(m[i%N]>h[(i-1)%N])//可以疊就繼續疊 
			h[i%N]=h[(i-1)%N]+1; 
		else
			h[i%N]=m[i%N];//不能就壓縮起來 
		if(h[i%N]>mx)mx=h[i%N];//紀錄最大值 
		if(mx==N)break;//全部玩完就結束 
	}
	
	cout<<mx<<'\n';
	return 0;
}
