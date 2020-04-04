#include<iostream>
using namespace std;

int main()
{
	int x,score=0;
	cin>>x;
	if(!(x%3))
		score+=3;
	if(!(x%5))
		score+=5;
	if(x>=100&&x<=200)
		score+=50;
	else
		score-=50; 
	if(x<=0)score=-100;
	cout<<score<<endl;
	return 0;
}

