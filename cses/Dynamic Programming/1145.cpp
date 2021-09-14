#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

int n, x;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<int> lis(1);
    cin >> n;
    while(n--){
        cin >> x;
        if(x > lis.back()){
            lis.push_back(x);
        }else{
            *lower_bound(lis.begin(), lis.end(), x) = x;
        }
    }
    cout << lis.size() - 1 << '\n';
    return 0;
}