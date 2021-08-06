#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define id(x) (x + BIAS)
const int MAX_X = 6e4;
const int MAX_N = 5e4 + 5;
const int BIAS = MAX_X >> 1;
int nu, nm, nl, ipt;
int m[MAX_N], cnt;
bitset<MAX_X + 1> u, l;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    // clock_t ct = clock();
    cin >> nu;
    // nu = 50000;
    rep(i, 0, nu){
        cin >> ipt;
        // ipt = i - 25000;;
        u[MAX_X - id(ipt)] = 1;
    }
    cin >> nm;
    // nm = 50000;
    rep(i, 0, nm){
        // m[i] = i - 25000;;
        cin >> m[i];
    }
    cin >> nl;
    // nl = 50000;
    rep(i, 0, nl){
        cin >> ipt;
        // ipt = i - 25000;;
        l[id(ipt)] = 1;
    }
    rep(i, 0, nm){
        if(m[i] < 1){
            m[i] *= -1;
            cnt += ((l << (m[i] << 1)) & u).count();
        }else{
            cnt += ((l >> (m[i] << 1)) & u).count();
        }
    }
    cout << cnt << '\n';
    // cout << clock() - ct << endl;
    return 0;
}