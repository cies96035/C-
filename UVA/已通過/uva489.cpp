#include<iostream>
#include<vector>
using namespace std;

#define wordsize 26
bool isoccured[wordsize];
vector<char> word;
int Round;
char c;

void Insert_word(char c)
{
	word.emplace_back(c);
	for(int i=word.size()-1;i>0;i--)
	{
		if(word[i]<word[i-1])
			swap(word[i],word[i-1]);
		else
			return;
	}
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin>>Round&&Round!=-1)
	{
		word.clear();
		cin.ignore();
		
		while(cin.get(c)&&c!='\n')
		{
			if(isoccured[c-'a']==0)
			{
				Insert_word(c);
				isoccured[c-'a']=1;
			}
		}
		for(int i=0;i<word.size();i++)
			cout<<word[i]<<endl;
		/*
		while(cin.get(c)&&c!='\n')
		{
			
		}*/
	}
	return 0;
}

