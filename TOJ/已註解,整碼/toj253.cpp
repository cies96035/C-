#include<iostream>
using namespace std;

bool isdecorate[26];//用來紀錄是否裝飾 

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
	while(m--)//紀錄是否裝飾 
	{
		cin>>d;
		isdecorate[--d]=!isdecorate[d];
	} 
	n-=2000;//方便計算... 
	for(int i=0;i<n;i++)//輸出樹葉 
		coutline(i,n-i-1,isdecorate[i]);
	coutstalk(n);//輸出莖 
	return 0;
}

