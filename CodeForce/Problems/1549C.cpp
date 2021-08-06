#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
int n, m, q, u, v;
int bcnt[MAX_N], cnt;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    cnt = n;
    while(m--){
        cin >> u >> v;
        if(!bcnt[min(u, v)]){
            cnt--;
        }
        bcnt[min(u, v)]++;
    }
    cin >> q;
    while(q--){
        cin >> m;
        if(m == 1){
            cin >> u >> v;
            if(!bcnt[min(u, v)]){
                cnt--;
            }
            bcnt[min(u, v)]++;
        }else if(m == 2){
            cin >> u >> v;
            bcnt[min(u, v)]--;
            if(!bcnt[min(u, v)]){
                cnt++;
            }
        }else{
            cout << cnt << '\n';
        }
    }

    return 0;
}