#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int MAX_M = 1000100;
const int MAX_N = 11;

struct STATE{
    ll s;
    int depth;
    bool operator < (const STATE &x) const{
        return depth > x. depth;
    }
    STATE(){};
    STATE(int a, int b):s(a), depth(b){}
};
int m, n, s;
bool used[MAX_M];
pll ab[MAX_N];
priority_queue<STATE> pq;
STATE sk;
int ans, tmp;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ans = -1;
    cin >> m >> n >> s;

    for(int i = 0; i < n; i++){
        cin >> ab[i].first >> ab[i].second;
    }

    pq.push( STATE(s, 0) );
    used[s] = true;
    while(!pq.empty()){
        sk = pq.top();
        pq.pop();
        if(sk.s == 0){
            ans = sk.depth;
            break;
        }
        used[sk.s] = true;
        for(int i = 0; i < n; i++){
            tmp = (sk.s * ab[i].first + ab[i].second) % m;
            if(!used[tmp]){
                pq.push( STATE( tmp, sk.depth + 1) );
                used[tmp] = true;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}