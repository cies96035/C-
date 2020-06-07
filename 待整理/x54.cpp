//∏’ß@°Aµ¥πÔTLE 

#include<iostream>
#include<cstring>
using namespace std;

struct S
{
	char first,end;
};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    while(cin>>N)
    {
    	if(N==0)return 0;
    	S s[N];
    	bool use[N];
    	memset(use,0,sizeof(use));
    	string word;
    	for(int i=0;i<N;i++)
    	{
    		cin>>word;
    		s[i].first=word[0];
    		s[i].end=word[word.size()-1];
		}
		int p=0,ans=0;
	    for(int i=0;i<N;i++)
    	{
    		for(int j=0;j<N;j++)
	    	{
	    		if(!use[j]&&s[p].end==s[j].first)
				{
					use[p]=1;
					p=j;
					ans++;
					break;
				}
	    	}
    	}
    	if(ans==N-1&&s[p].end==s[0].first)
    	{
    		cout<<"OK"<<endl;
		}
		else
		{
			cout<<"NG"<<endl;
		}
	}
}
