#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define wordsize 26
int isoccured[wordsize];
vector<char> word;
int Round,wrong,correct;
char c;

void Insert_word(char c)
{
	word.emplace_back(c);
	for(int i=word.size()-1;i>0;i--)
		if(word[i]<word[i-1])
			swap(word[i],word[i-1]);
		else
			return;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin>>Round&&Round!=-1)
	{
		//Init
		cin.ignore();
		wrong=7;
		correct=1;
		word.clear();
		memset(isoccured,0,sizeof(isoccured));
		
		while(cin.get(c)&&c!='\n')
		{
			if(isoccured[c-'a']==0)
			{
				Insert_word(c);
				isoccured[c-'a']=1;
			}
		}
		
		//make sure lower_bound correct
		word.emplace_back('z'+1);
		
		while(cin.get(c)&&c!='\n')
		{
			//if guess again
			if(isoccured[c-'a']==-1)
				continue;
			isoccured[c-'a']=-1;
			
			//wrong or correct
			if(*lower_bound(word.begin(),word.end(),c)==c)
				correct++;
			else
				wrong--;
			
			if(wrong>0&&correct==word.size())//Win
				wrong=1e9;
		}
		
		//output
		cout<<"Round "<<Round<<'\n';
		if(wrong>0&&correct==word.size())//win
			cout<<"You win.\n";
		else if(wrong>0)//didnt guess enough
			cout<<"You chickened out.\n";
		else //lose
			cout<<"You lose.\n";
	}
	return 0;
}

