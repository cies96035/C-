#include<iostream>
using namespace std;

const int maxA=10000001;
pair<int,int> prime[maxA];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//先把i.second值設為1，讓只有一個質因數時可以正確輸出1和質因數 
	for(int i=2;i<maxA;i++)
		prime[i].second=1;
		
	//篩法，把質因數丟進去質因數的倍數裡，只求前兩大的質因數 
	for(int i=2;i<maxA;i++)
		if(!prime[i].first)
			for(int j=i;j<maxA;j+=i)
			{
				prime[j].first=i;
				swap(prime[j].first,prime[j].second);
			}
	
	/*
	int N,A;
	
	cin>>N;
	while(N--)
	{
		cin>>A;
		//直接輸出該數字前兩大的質因數即可 
		cout<<prime[A].first<<' '<<prime[A].second<<'\n';
	}*/
	return 0;
}

