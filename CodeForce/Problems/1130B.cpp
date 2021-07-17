#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 100100;
int n, ipt;
pii pos[MAX_N];
ll disum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    n <<= 1;
    for(int i = 1; i <= n; i++){
        cin >> ipt;
        if(!pos[ipt].first){
            pos[ipt].first = i;
        }else{
            pos[ipt].second = i;
        }
    }
    n >>= 1;
    pos[0].first = pos[0].second = 1;
    for(int i = 1; i <= n; i++){
        disum += min(
            abs(pos[i].first - pos[i - 1].first) + 
            abs(pos[i].second - pos[i - 1].second),
            abs(pos[i].first - pos[i - 1].second) + 
            abs(pos[i].second - pos[i - 1].first)
        );
    }
    cout << disum << '\n';
    return 0;
}