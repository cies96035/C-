#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N,start,high,down,todown;
	cin>>N;
	N--;
	cin>>high>>start;
	todown=start+high;
	while(N--)
	{
		cin>>high>>start;
		if(todown<start)break;
		if((down=high+start)>todown)todown=down;
	}
	if(!(++N))
		cout<<"hurray\n";
	else
		cout<<N<<'\n'; 
	return 0;
}

