#include<iostream>
using namespace std;

int main() 
{
	char a[3][3],flag=0;
	
	/* 輸入
	00 01 02
	10 11 12
	20 21 22
	*/ 
	for(int k1=0;k1<3;k1++)
		for(int k2=0;k2<3;k2++)
		{
			cin>>a[k1][k2];
			if(a[k1][k2]=='#')flag=1;
		}

	//判斷橫行是否相同，相同時判斷誰得分 
	for(int k2=0;k2<3;k2++)
		if(a[0][k2]==a[1][k2]&&a[0][k2]==a[2][k2])
		{
			if(a[0][k2]=='X')
			{
				cout<<"B wins."<<endl;
				return 0;
			}
			if(a[0][k2]=='O')
			{
				cout<<"A wins."<<endl;
				return 0;
			}
		}
	
	//判斷直行是否相同，相同時判斷誰得分
	for(int k1=0;k1<3;k1++)
		if(a[k1][0]==a[k1][1]&&a[k1][0]==a[k1][2])
		{
			if(a[k1][0]=='X')
			{
				cout<<"B wins."<<endl;
				return 0;
			}
			if(a[k1][0]=='O')
			{
				cout<<"A wins."<<endl;
				return 0;
			}
		}
	//判斷左上右下斜行是否相同，相同時判斷誰得分
	if(a[0][0]==a[1][1]&&a[0][0]==a[2][2])
	{
		if(a[0][0]=='X')
		{
			cout<<"B wins."<<endl;
			return 0;
		}
		if(a[0][0]=='O')
		{
			cout<<"A wins."<<endl;
			return 0;
		}
	}
	//判斷右上左下斜行是否相同，相同時判斷誰得分
	if(a[0][2]==a[1][1]&&a[0][2]==a[2][0])
	{
		if(a[0][2]=='X')
		{
			cout<<"B wins."<<endl;
			return 0;
		}
		if(a[0][2]=='O')
		{
			cout<<"A wins."<<endl;
			return 0;
		}
	}
	if(flag)
	{
		cout<<"Playing"<<endl;
		return 0;
	}
	cout<<"Draw"<<endl;
	return 0;
}
