#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N,T,a,b;
	bool quit=0;
	cin>>N;
	int id[N+1];
	
	//��J 
	for(int i=1;i<=N;i++)
		cin>>id[i];
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		if(a-b>8||b-a>8)//�D�رԭz���I���D�A��ڤW�O�j�W�L8���ɮ�(�Z���W�L9 
			quit=1;
		if(!quit)
			swap(id[a],id[b]);
	}
	
	//��X 
	if(quit)
		cout<<"I QUIT!"<<endl;
	else
		cout<<"SORTED!"<<endl;
	for(int i=1;i<N;i++)
		cout<<id[i]<<' ';
	cout<<id[N]<<endl;
	return 0;
}

