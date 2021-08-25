#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e5 + 5;
int t;
int k, n;
int a[MAX_N], b[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n >> k;
        rep(i, 0, n){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        map<int, int> dict;
        rep(i, 0, n){
            dict[ b[i] ] = i;
        }
        int cnt = 0;
        int aed = a[0];
        rep(i, 1, n){
            if(dict[aed] + 1 != dict[a[i]]){
                cnt++;
            }
            aed = a[i];
        }
        if(cnt < k){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}