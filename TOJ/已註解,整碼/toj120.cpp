#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//前綴和觀念稍微有就不會TLE
	int N,num,Q;
	cin>>N;
	long long Snum[N+1]={0};//儲存a0~an的總和(題目數字稍大要開long long 
	
	for(int i=1;i<=N;i++)
	{
		cin>>num;
		Snum[i]=Snum[i-1]+num;
	}
	
	//輸出 
	cin>>Q;
	while(Q--)
	{
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);//求a,b區間和，並沒說a必小於b
		cout<<Snum[b]-Snum[a-1]<<endl;
	}
	return 0;
}

