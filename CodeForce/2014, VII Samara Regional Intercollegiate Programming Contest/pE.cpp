#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e5 + 5;
const int MAX_T = 3.5e4;
ll n, m;
unordered_map<ll, ll> dict;

ll arr[MAX_N];

vector<ll> prime;
bool isntprime[MAX_T];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    rep(i, 2, MAX_T){
        if(!isntprime[i]){
            for(ll j = i * i; j < MAX_T; j += i){
                isntprime[i] = true;
            }
            prime.push_back(i);
        }
    }
    for(auto p : prime) cout << p << ' ' ;
    cout << endl;
    cin >> n >> m;
    rep(i, 0, n) cin >> arr[i];
    
    return 0;
}