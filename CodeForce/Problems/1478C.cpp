#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e5;
int t, n;
int d[MAX_N << 1];
int num[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        int s = 0;
        cin >> n;
        for(int i = 0, e = n << 1; i < e; i++){
            cin >> d[i];
            s ^= d[i];
            if(d[i] & 1){
                s ^= -i;
            }
        }
        // cout << s << "AAA" <<endl;
        bool flg = s;
        int sum = 0, s2 = 0;
        sort(d, d + (n << 1));
        num[0] = 0;
        rep(i, 1, n){
            num[i] = num[i - 1] + (d[i << 1] - d[(i << 1) - 1]) / 2;
            cout << num[i] << endl;
            sum += num[i];
        }
        rep(i, 0, n){
            cout << d[i << 1] << ' ';
        }
        cout << endl;
        if(sum > d[0] || (sum - d[0]) % n){
            flg = true;
        }
        cout << sum << endl;
        if(flg){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
    return 0;
}