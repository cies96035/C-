#include<iostream>
using namespace std;

int ans[1000002]={0,3};//�����C�ӵ��� 

inline int getans(int n)//����1~n-1��n���誺���X�ӡA�[�i�h�}�C 
{
	int a,b,Ans=0;
	bool two=!n%2;
	for(int num=n-1;num>0;num--)
	{
		a=num,b=n;
		if(two&&!num%2)continue;
		while((a%=b)&&(b%=a));
		if(a+b==1)Ans++;
	}
	return Ans;
}
int main()
{
	/*
	�p�Ga,b�ݱo��A�hb,a�ݱo��A�ҥH�u�n�p��@�b�Y�i(*2) 
	0,1 1,0 1,1�A���ݱo��A�S�� 
	1,2 1,3 2,3 2,5...�o�Ǥ���A�ݱo��
	2,4 2,6 3,6...�o�Ǥ�����A���ݤ��� 
	*/
	for(int i=2;i<10000;i++)
	{
		//ans[i]=ans[i-1]+getans(i)*2;
	}
	int N;
	while(cin>>N)
	{
		cout<<getans(N)<<endl;
	}
	return 0;
}

