#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int t, n, a[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        int cnt1 = 0, cntn1 = 0;
        cin >> n;
        rrep(i, 1, n){
            cin >> a[i];
            if(a[i] == 1) cnt1++;
            else if(a[i] == -1) cntn1++;
        }
        if((cnt1 + cntn1) & 1){
            cout << "-1\n";
        }else{
            set<pll> ans;
            rep(i, 1, n){
                if(cnt1 > cntn1){
                    if(a[i + 1] == 1){
                        ans.insert({i, i + 1});
                        i++;
                        cnt1--;
                        cntn1++;
                    }else{
                        ans.insert({i, i});
                    }
                }else if(cnt1 < cntn1){
                    if(a[i + 1] == -1){
                        ans.insert({i, i + 1});
                        i++;
                        cnt1++;
                        cntn1--;
                    }else{
                        ans.insert({i, i});
                    }
                }else{
                    ans.insert({i, i});
                }
            }
            if(ans.empty() || ans.rbegin()->second != n) ans.insert({n, n});
            cout << ans.size() << '\n';
            for(auto p : ans){
                cout << p.first << ' ' << p.second << '\n';
            }
        }
    }
    return 0;
}