#include<iostream>
using namespace std;

int main()
{
	char todo;
	int X,Y,num;
	while(cin>>todo)
	{
		if(todo=='B')continue;//�}�l���O 
		if(todo=='E')break;//�������O
		cin>>num;
		//�]�� 
		if(todo=='X')X=num;
		else if(todo=='Y')Y=num;
		//�վ�� 
		else if(todo=='U')Y+=num;
		else if(todo=='D')Y-=num;
		else if(todo=='R')X+=num;
		else if(todo=='L')X-=num;
	}
	cout<<X<<endl<<Y<<endl; 
	return 0;
}

