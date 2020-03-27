#include<iostream>
using namespace std;

const int maxA=10000001;
pair<int,int> prime[maxA];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//����i.second�ȳ]��1�A���u���@�ӽ�]�Ʈɥi�H���T��X1�M��]�� 
	for(int i=2;i<maxA;i++)
		prime[i].second=1;
		
	//�z�k�A���]�ƥ�i�h��]�ƪ����Ƹ̡A�u�D�e��j����]�� 
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
		//������X�ӼƦr�e��j����]�ƧY�i 
		cout<<prime[A].first<<' '<<prime[A].second<<'\n';
	}*/
	return 0;
}

