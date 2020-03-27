#include<iostream>
using namespace std;

int main()
{
	char todo;
	int X,Y,num;
	while(cin>>todo)
	{
		if(todo=='B')continue;//開始指令 
		if(todo=='E')break;//結束指令
		cin>>num;
		//設值 
		if(todo=='X')X=num;
		else if(todo=='Y')Y=num;
		//調整值 
		else if(todo=='U')Y+=num;
		else if(todo=='D')Y-=num;
		else if(todo=='R')X+=num;
		else if(todo=='L')X-=num;
	}
	cout<<X<<endl<<Y<<endl; 
	return 0;
}

