#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
const int MAX_M = 1e3 + 5;
int n, m, k;
int a[MAX_N], b[MAX_N][5];
vector<int> sc[MAX_M];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m >> k;
    if(n != k){
        cout << -1 << endl;
    }
    rrep(i, 1, n){
        cin >> a[i];
    }
    rrep(i, 1, n){
        rep(j, 0, 5){
            cin >> b[i][j];
        }
    }
    rrep(i, 1, n){
        rep(j, 0, 5){
            if(sc[ b[ a[i] ][j] ].size() < k){
                sc[ b[ a[i] ][j] ].emplace_back(a[i]);
                break;
            }
        }
    }
    rrep(i, 1, m){
        cout << sc[i].size() << ' ';
        sort(sc[i].begin(), sc[i].end());
        for(auto j : sc[i]){
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}