#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
string n;
string two[64];
string num_to_str(ll n){
    string ans = "";
    while(n){
        ans += char('0' + n % 10);
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int getans(string a, string b){
    int l[20][20];
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            l[i][j] = 0;
        }
    }
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]){
                l[i + 1][j + 1] = l[i][j] + 1;
            }else{
                l[i + 1][j + 1] = max(l[i][j + 1], l[i + 1][j]);
            }
        }
    }
    return l[a.size()][b.size()];

}
int ggetans(string a, string b){
    int i = 0, j = 0;
    int cnt = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] != b[j]){
            cnt++;
            i++;
        }else{
            i++, j++;
        }
    }//75 1
    if(i == a.size()){
        // if(a == "75")
        // cout << j << endl;
        return b.size() - j + cnt;
    }else{
        return a.size() - i + cnt;
    }
    return 0;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(ll i = 0, k = 1; k < 1e18; k *= 2, i++){
        two[i] = num_to_str(k);
        // cout << k << endl;
        // cout << two[i] << endl;
        // cout << i << endl;
    }
    cin >> t;
    while(t--){
        ll ans = 100, gg = 100;
        cin >> n;
        rep(i, 0, 60){
            ans = min(ans, ll(ggetans(n, two[i])));
            // if(ans != gg){
            //     cout << ans << ' ' << n << ' ' << two[i] << endl;
            // }
            // gg = ans;
            // ans = min(ans, ll(n.size() - getans(n, two[i]) * 2 + two[i].size()));
        }
        cout << ans << '\n';
    }
    return 0;
}