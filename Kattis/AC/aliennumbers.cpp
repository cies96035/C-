#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    ll num;
    string alien_number, source_language, target_language, ans;
    cin >> T;
    
    rrep(i, 1, T){
        cout << "Case #" << i << ": ";

        cin >> alien_number >> source_language >> target_language;
        num = 0;
        for(auto c : alien_number){
            rep(i, 0, source_language.size()){
                if(c == source_language[i]){
                    num = num * source_language.size() + i;
                }
            }
        }

        ans.clear();
        while(num){
            ans += target_language[num % target_language.size()];
            num /= target_language.size();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;

    }
    return 0;
}