#include<iostream>
using namespace std;

bool isdecorate[26];//�ΨӬ����O�_�˹� 

void coutline(int n,int shift,bool decorate)
{
	while(shift--)cout<<' ';
	if(decorate)
	{
		for(int i=0;i<n;i++)cout<<(char)('A'+i);
		for(int i=n;i>=0;i--)cout<<(char)('A'+i);
	}
	else
	{
		for(int i=0;i<=2*n;i++)cout<<'*';
	}
	cout<<endl;
}
void coutstalk(int n)
{
	for(int i=1;i<n;i++)
	{
		cout<<' ';
		for(int j=3;j<2*n;j++)cout<<'^';
		cout<<endl;
	}
}
int main()
{
	int n,m,d;
	cin>>n>>m;
	while(m--)//�����O�_�˹� 
	{
		cin>>d;
		isdecorate[--d]=!isdecorate[d];
	} 
	n-=2000;//��K�p��... 
	for(int i=0;i<n;i++)//��X�� 
		coutline(i,n-i-1,isdecorate[i]);
	coutstalk(n);//��X�� 
	return 0;
}

