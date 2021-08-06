#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n;
string str;
vector<string> mex;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(string i = "a"; i[0] <= 'z'; i[0]++){
        mex.emplace_back(i);
    }
    for(int i = 0; i < 26; i++){
        for(char j = 'a'; j <= 'z'; j++){
            mex.emplace_back(mex[i] + j);
        }
    }
    for(int i = 26; i < 702; i++){
        for(char j = 'a'; j <= 'z'; j++){
            mex.emplace_back(mex[i] + j);
        }
    }
    cin >> t;
    while(t--){
        cin >> n >> str;
        for(int i = 0; true; i++){
            if(str.find(mex[i], 0) == -1){
                cout << mex[i] << '\n';
                break;
            }
        }
    }
    return 0;
}