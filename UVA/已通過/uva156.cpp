#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;

#define MAXAMOUNT 1050

string str;
struct WORD
{
	//TrueWord ComPareWord
	string TW,CPW;
	//Init
	WORD(string a,string b)
	{
		TW=a;
		CPW=b;
	}
};
vector<string> TWord;
vector<WORD> words;

//normalize
string tolower(string origin)
{
	for(int i=0;i<origin.size();i++)
		if('A'<=origin[i]&&origin[i]<='Z')
			origin[i] += 'a'-'A';
	return origin;
}
//sort by CPW
bool cmp(WORD a,WORD b)
{
	return a.CPW<b.CPW;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//INPUT
	while(cin>>str&&str!="#")
	{
		words.emplace_back(WORD(str,tolower(str)));
		sort(words.back().CPW.begin(),words.back().CPW.end());
	}
	
	//sort by compareword
	sort(words.begin(),words.end(),cmp);
	
	//find words that occurred over two times;
	//and flag them
	for(int i=1;i<words.size();i++)
		if(words[i].CPW==words[i-1].CPW)
			words[i].TW=words[i-1].TW="-1";
		
	//Collect that only occurred one time
	//And sort them
	for(int i=0;i<words.size();i++)
		if(words[i].TW!="-1")
			TWord.emplace_back(words[i].TW);
	sort(TWord.begin(),TWord.end());
	
	//Output
	for(int i=0;i<TWord.size();i++)
		cout<<TWord[i]<<'\n';
			
	return 0;
}

