#include<iostream>
using namespace std;

char Ra[]={"A   3  HIL JM O   2TUVWXY5"},Rn[]={"1SE Z  8 "};

#define isnum(n) (n>='0'&&n<='9')
bool isP(string S)
{
	int i=0,j=S.size()-1;
	while(i<j)
	{
		if(S[i]!=S[j])return 0;
		i++;
		j--;
	}
	return 1;
}
bool isM(string S)
{
	int i=0,j=S.size()-1;
	while(i<=j)
	{
		if(isnum(S[i]))
		{
			if(S[j]!=Rn[S[i]-'1'])return 0;
		}
		else
			if(S[j]!=Ra[S[i]-'A'])return 0;
		i++;
		j--;
	}
	return 1;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string S;
	while(cin>>S)
	{
		if(isP(S))
		{
			if(isM(S))
				cout<<S<<" -- is a mirrored palindrome.\n";
			else
				cout<<S<<" -- is a regular palindrome.\n";
		}
		else if(isM(S))cout<<S<<" -- is a mirrored string.\n";
		else cout<<S<<" -- is not a palindrome.\n";
		cout<<'\n';
	}
	return 0;
}

