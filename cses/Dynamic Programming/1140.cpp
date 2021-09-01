#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
tuple<int, int, ll> jobs[MAX_N];
map<int, ll> dp;
ll n, Max, a, b, p;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    dp[0] = 0;

    cin >> n;
    rep(i, 0, n){
        cin >> a >> b >> p;
        jobs[i] = tie(b, a, p);
    }
    sort(jobs, jobs + n);

    rep(i, 0, n){
        Max = max(Max, (--dp.lower_bound(get<1>(jobs[i])))->second + get<2>(jobs[i]));
        dp[get<0>(jobs[i])] = Max;
    }

    cout << Max << '\n';
    return 0;
}