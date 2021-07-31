#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200005;
int BIT[6][MAX_N];
int n, m;
int l, r;
string str;
void add(int id, int x){
    while(x < MAX_N){
        BIT[id][x]++;
        x += x & -x;
    }
}
int query(int id, int x){
    int s = 0;
    while(x){
        s += BIT[id][x];
        x -= x & -x;
    }
    return s;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    rep(i, 0, 6){
        rep(j, 0, MAX_N){
            BIT[i][j] = 0;
        }
    }
    cin >> n >> m >> str;
    string T = "abc";
    rep(i, 0, 6){
        rep(j, 0, n){
            if(T[j % 3] != str[j]){
                add(i, j + 1);
            }
        }
        next_permutation(T.begin(), T.end());
    }
    while(m--){
        cin >> l >> r;
        int Min = MAX_N;
        rep(i, 0, 6){
            Min = min(Min, query(i, r) - query(i, l - 1));
        }
        cout << Min << '\n';
    }
    return 0;
}