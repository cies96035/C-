#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 450;
int a[MAX_N];
bool flg;
int q, n;
int s;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> q;
    while(q--){
        flg = true;
        cin >> n;
        n *= 4;
        rep(i, 0, n){
            cin >> a[i];
        }
        sort(a, a + n);
        s = a[0] * a[n - 1];
        for(int i = 0, j = n - 1; i < j; i += 2, j -= 2){
            if(a[i] != a[i + 1] || a[j] != a[j - 1] || a[i] * a[j] != s){
                flg = false;
                break;
            }
        }
        if(flg){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}