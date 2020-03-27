#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    cin>>T;
    while(T--)
    {
        string s;
		vector<string> alpha[26];
        int N;
		cin>>s;
		for(int i=0;i<s.size();i++)
			alpha[s[i]-'a'].push_back(s.substr(i,50));
		cin>>N;
        while(N--)
        {
            string keyword;
			cin>>keyword;
			int index=keyword[0]-'a';
			bool isfind=0;
			for(int i=0;i<alpha[index].size();i++)
			{
				if(alpha[index][i].find(keyword)!=-1)
				{
					cout<<"y\n";
					isfind=1;
					break;
				}
			}
			if(!isfind)cout<<"n\n";
        }
    }
    return 0;
}
