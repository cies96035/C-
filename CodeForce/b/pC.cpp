#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int INF = 0x3fffffff;
const int MAX_N = 1e5 + 5;

int t, n;
string str[MAX_N], table[MAX_N];

inline int cost(int l, int r, int x){ //x in [l, r),
    return min(x - l, r - x);
}

inline int lb(int l, int r, char c, int len){
    int mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(table[mid].size() <= len || table[mid][len] < c){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> str[i];
            table[i] = str[i];
        }
        
        sort(table, table + n);
        
        int l, r, pos, len, ans;
        rep(i, 0, n){
            pos = lower_bound(table, table + n, str[i]) - table; // str[i] pos
            l = 0, r = n, len = 0; //[l, r), [0, j)
            ans = cost(l, r, pos);

            while(r - l > 1){
                l = lb(l, r, str[i][len], len);
                r = lb(l, r, str[i][len] + 1, len);
                len++;

                ans = min(ans, cost(l, r, pos) + len);
            }
            cout << ans + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}