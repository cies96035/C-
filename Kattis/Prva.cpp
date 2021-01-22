#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXRC 25
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<string> words;
    int R, C;
    cin >> R >> C;
    char k[MAXRC][MAXRC];
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> k[i][j];
    
    for(int i = 0; i < R; i++)
        k[i][C] = '#';

    for(int i = 0; i < C; i++)
        k[R][i] = '#';
    
    string tmp;
    for(int i = 0; i < R; i++)
        for(int j = 0; j <= C; j++)
        {
            if(k[i][j] != '#')
                tmp += k[i][j];
            else
            {
                if(tmp.size() >= 2)
                    words.emplace_back(tmp);
                tmp.clear();
            }            
        }

    for(int i = 0; i < C; i++)
        for(int j = 0; j <= R; j++)
        {
            if(k[j][i] != '#')
                tmp += k[j][i];
            else
            {
                if(tmp.size() >= 2)
                    words.emplace_back(tmp);
                tmp.clear();
            }            
        }

    sort(words.begin(), words.end());
    cout << words[0] << '\n';
    return 0;
}