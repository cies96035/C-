#include<iostream>
using namespace std;

#define toint(x) (x-'a')
#define alphasize 26

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	 
	int N;
	while(cin>>N&&N>0)
	{
		string word;
		int Begin[alphasize]={0},End[alphasize]={0};
		bool is_ok=1;
		while(N--)
		{
			cin>>word;
			Begin[toint(word.front())]++;
			End[toint(word.back())]++;
		}
		for(int i=0;i<alphasize;i++)
			if(Begin[i]!=End[i])
			{
				is_ok=0;
				break;
			}
		if(is_ok) cout<<"OK\n";
		else cout<<"NG\n";
	}
	return 0;
}

