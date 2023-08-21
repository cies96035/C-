#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int arr[30];
vector<pll> op;
void f(){
    op.clear();
    int n;
    int ma = 1, mi = 1, maa = -20, mii = 20;
    cin >> n;
    rrep(i, 1, n){
        cin >> arr[i];
        if(arr[ma] < arr[i]){
            ma = i;
        }
        if(arr[mi] > arr[i]){
            mi = i;
        }
        maa = max(maa, arr[i]);
        mii = min(mii, arr[i]);
    }
    for(int )
    bool flg = -mii <= maa;
    // cout << maa << ' ' << mii << ' ' << ma << ' ' << mi << endl;
    if(flg){
        op.push_back({n, ma});
        op.push_back({n, ma});
        op.push_back({n, n});
        rrep(i, 1, n - 1){
            op.push_back({i, n});
            op.push_back({n, n});
        }
    }else{
        op.push_back({1, mi});
        op.push_back({1, mi});
        op.push_back({1, 1});
        rvep(i, n, 2){
            op.push_back({i, 1});
            op.push_back({1, 1});
        }
    }
    cout << op.size() << '\n';
    for(auto o:op){
        cout << o.first << ' ' << o.second << '\n';
    }

}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--){
        f();
    }
    return 0;
}