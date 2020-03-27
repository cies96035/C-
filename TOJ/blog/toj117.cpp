#include<iostream>
using namespace std;

int main()
{
	int a,score,highscore;
	cin>>a;
	while(a--)
	{
		cin>>score;
		if(score>highscore)highscore=score;
	}
	cout<<highscore<<endl;
	return 0;
}

