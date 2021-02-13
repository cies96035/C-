#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
using pii = pair<int,int>;
using pis = pair<int,string>;

map<char, pii> keyPos;
int cmp(string a, string b)
{
    int dis = 0;
    for(int i = 0; i < a.size(); i++)
    {
        pii aPos = keyPos[ a[i] ]; 
        pii bPos = keyPos[ b[i] ]; 
        dis += std::abs(aPos.first - bPos.first) + std::abs(aPos.second - bPos.second);
    }
    return dis;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    const string key[3]={
        "qwertyuiop",
        "asdfghjkl",
        "zxcvbnm"
    };
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < key[i].size(); j++)
            keyPos[ key[i][j] ] = pii(i, j);

    string s, stmp;
    vector<pis> words;
    int n;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s >> n;
        while(n--)
        {
            cin >> stmp;
            words.emplace_back( pis(cmp(s, stmp), stmp) );
        }
        sort(words.begin(), words.end());
        for(auto w : words)
            cout << w.second << ' ' << w.first << '\n';
        words.clear();
    }
    return 0;
}