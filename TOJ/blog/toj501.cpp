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
	
	for(int i=1,end=2*N-1;i<end;i++)//�]��¶��A����⭿�� 
	{
		if(m[i%N]>h[(i-1)%N])//�i�H�|�N�~���| 
			h[i%N]=h[(i-1)%N]+1; 
		else
			h[i%N]=m[i%N];//����N���Y�_�� 
		if(h[i%N]>mx)mx=h[i%N];//�����̤j�� 
		if(mx==N)break;//���������N���� 
	}
	
	cout<<mx<<'\n';
	return 0;
}
