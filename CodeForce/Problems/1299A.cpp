#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n;
int a[100010];
int t;
int ans = 0;
int tmp;
int Maxpos;
int f(int a, int b){
    return (a | b) - b;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> a[i];
        tmp = ans & a[i] | tmp;
        ans |= a[i];
    }
    ans = ans & (~tmp);
    // cout << ans << endl;
    rep(i, 0, n){
        // cout << a[i] << ' ' << (ans & a[i]) << endl;
        if((ans & a[i]) > (ans & a[Maxpos])){
            Maxpos = i;
        }
    }
    swap(a[0], a[Maxpos]);
    rep(i, 0, n - 1){
        cout << a[i] << ' ';
    }
    cout << a[n - 1] << '\n';
    // bitset<32> tt;
    // tt = tmp;
    // cout << tt.to_string() << endl;
    // rep(i, 0, n){
    //     tt = a[i];
    //     cout << a[i] << ' ' << tt.to_string() << '\n';
    // }
    // sort(a, a + n);
    // do{
    //     t = a[0];
    //     rep(i, 1, n){
    //         t = f(t, a[i]);
    //     }
    //     rep(i, 0, n){
    //         cout << a[i] << ' ';
    //     }
    //     cout << endl;
    //     cout << t << endl;
    // }while(next_permutation(a, a + n));
    return 0;
}