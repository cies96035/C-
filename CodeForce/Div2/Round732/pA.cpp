#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 150;
int t, n;
int a[MAX_N], b[MAX_N];
int cnt = 0;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cnt = 0;
        vector<pii> ans;
        queue<pii> Add, Minus;
        cin >> n;
        rep(i, 0, n){
            cin >> a[i];
        }
        rep(i, 0, n){
            cin >> b[i];
            if(a[i] > b[i]){
                Minus.push( pii(a[i] - b[i], i) );
            }else if(a[i] < b[i]){
                Add.push( pii(b[i] - a[i], i) );
            }
            cnt += a[i] - b[i];
        }
        if(cnt != 0){
            cout << "-1\n";
        }else{
            while(!Add.empty()){
                ans.push_back( pii(Add.front().second, Minus.front().second) );
                Add.front().first--;
                Minus.front().first--;
                if(Add.front().first == 0){
                    Add.pop();
                }
                if(Minus.front().first == 0){
                    Minus.pop();
                }
            }
            cout << ans.size() << '\n';
            for(auto aa : ans){
                cout << aa.second + 1 << ' ' << aa.first + 1 << '\n';
            }
        }
    }
    return 0;
}