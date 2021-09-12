#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define ALL(x) x.begin(), x.end()

using ll = long long;

const ll INF = 1000000000000;
const ll V = 100005;

char cc[] = {
    'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'
};

int num[26];

vector <int> v;

int t = 0;

void solve() {
    int k;
    string s;
    cin >> k >> s;
    // k = t++;
    // cout << t << endl;
    // s = "A";
    v.clear();

    for(int i = s.size() - 1; i >= 0; --i)
        v.emplace_back(num[s[i] - 'A']);
    
    // for(int i = 11, j = 11, ct = 1; i <= k; ct++){
    //     if(v.size() <= ct){
    //         v.emplace_back(0);
    //     }
    //     i = i * 11 + j;
    //     j = i;
    // }
    // cout << v.size() << endl;
    int carry = 0;
    for (int i = 0; k || carry; ++i, k /= 11) {
        cout << k << ' ' << i << endl;
        if(i == v.size()) {
            v.emplace_back(0);
            v[i] += ((k + carry + 10) % 11);
            k--;
            // if(carry)
            // else{
            //     v[i] += (k % 11) + carry;
            // }
                // v[i] += (k - 1) % 11 + carry;
            // else
            //     v[i] += carry - 1;
        }
        else
            v[i] += (k + carry) % 11;
       
        carry = v[i] / 11;
        v[i] %= 11;
    }

    if (carry)
        v.emplace_back(carry - 1);
    
    reverse(ALL(v));

    // for (auto &x : v)
    //     cout << x << ' ';
    // cout << endl;
    for (auto &x : v)
        cout << cc[x];
    cout << endl;
}


signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 11; ++i)
        num[cc[i] - 'A'] = i;

    int t;
    cin >> t;
    while (t--) 
        solve();
}