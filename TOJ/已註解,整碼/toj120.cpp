#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//�e��M�[���y�L���N���|TLE
	int N,num,Q;
	cin>>N;
	long long Snum[N+1]={0};//�x�sa0~an���`�M(�D�ؼƦr�y�j�n�}long long 
	
	for(int i=1;i<=N;i++)
	{
		cin>>num;
		Snum[i]=Snum[i-1]+num;
	}
	
	//��X 
	cin>>Q;
	while(Q--)
	{
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);//�Da,b�϶��M�A�èS��a���p��b
		cout<<Snum[b]-Snum[a-1]<<endl;
	}
	return 0;
}

