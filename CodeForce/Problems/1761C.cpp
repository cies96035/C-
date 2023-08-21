#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e3 + 5;
bool b[MAX_N][MAX_N];
int cnt[MAX_N];
set<int> s[MAX_N];
priority_queue<pll, vector<pll>, greater<pll>> pq;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, n;
    char c;
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            s[i].clear();
            s[i].insert(i + 1);
            rep(j, 0, n){
                cin >> c;
                b[i][j] = c - '0';
                if(b[i][j]){
                    cnt[j]++;
                }
            }
        }
        rep(i, 0, n){
            pq.push({cnt[i], i});
        }
        while(!pq.empty()){ // n^3
            auto tmp = pq.top(); pq.pop();
            rep(i, 0, n){
                if(b[i][tmp.second]){
                    for(auto e : s[i]){
                        s[tmp.second].insert(e);
                    }
                }
            }
        }
        rep(i, 0, n){
            cout << s[i].size();
            for(auto e : s[i]){
                cout << ' ' << e;
            }
            cout << '\n';
            s[i].clear();
        }

    }
    return 0;
}