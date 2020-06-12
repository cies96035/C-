#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

#define words_find(words,k) lower_bound(words.begin(),words.end(),k)-words.begin()

inline bool togoBFS(string a,string b)
{
	if(a.size()!=b.size())return false;
	bool one_change=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i])
		{
			if(one_change)return false;
			one_change=1;
		}
	}
	if(one_change)return true;
	else return false;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t;
	cin>>t;
	cin.get();
	while(t)
	{
		string word;
		vector<string> words;
		while(getline(cin,word))
		{
			if(word=="*")
				break;
			else
				words.push_back(word);
		}
		sort(words.begin(),words.end());
		while(getline(cin,word))
		{
			int visited[words.size()]={0},space=word.find(' ');
			if(word=="")break;
			string start,end;
			start=word.substr(0,space);
			end=word.substr(space+1,word.size()-space);
			
			queue<string> BFS;
			BFS.push(start);
			visited[words_find(words,start)]=1;
			while(!BFS.empty())
			{
				string togo=BFS.front();
				BFS.pop();
				if(togo==end)
				{
					cout<<start<<' '<<end<<' '<<visited[words_find(words,togo)]-1<<'\n';
					break;
				}
				for(unsigned int i=0;i<words.size();i++)
				{ 
					if(togoBFS(togo,words[i])&&!visited[i])
					{
						BFS.push(words[i]);
						visited[i]=visited[words_find(words,togo)]+1;
					} 
				} 
			}
		}
		if(--t)cout<<'\n';
	}
	return 0;
}

