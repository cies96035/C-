#include<iostream>
using namespace std;

void coutline(char k,int shift)
{
	while(shift--)cout<<' ';
	for(int i=(k-'A')*2+1;i>0;i--)cout<<k;
	cout<<endl;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N,shift=0;
	char word;
	cin>>N;
	word=N+'A';
	while(word-->'A')
	{
		coutline(word,shift);
		shift++;
	}
	return 0;
}

