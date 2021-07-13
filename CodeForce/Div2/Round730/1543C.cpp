#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, a, b) for(int i = a; i < b; i++)
const ld eps = 1e-8;
const ld Inval = -10;
int t;
// int cnt = 0;
ld FindAns(ld c, ld m, ld p, ld v, int depth, ld P){
    // cnt++;
    // cout << c << ' ' << m << ' ' << p << ' ' << v << ' ' << depth << ' ' << P << endl;
    // system("PAUSE");
    if(c < -1 && m < -1){
        return P * depth;
    }
    ld ans = 0;
    if(c > -1){
        if(m < -1){
            if(c < v + eps){
                ans += FindAns(Inval, Inval, p + c, v, depth + 1, P * c);
            }else{
                ans += FindAns(c - v, Inval, p + v, v, depth + 1, P * c);
            }
        }else{
            if(c < v + eps){
                ans += FindAns(Inval, m + c / 2, p + c / 2, v, depth + 1, P * c);
            }else{
                ans += FindAns(c - v, m + v / 2, p + v / 2, v, depth + 1, P * c);
            }
        }
    }
    if(m > -1){
        if(c < -1){
            if(m < v + eps){
                ans += FindAns(Inval, Inval, p + m, v, depth + 1, P * m);
            }else{
                ans += FindAns(Inval, m - v, p + v, v, depth + 1, P * m);
            }
        }else{
            if(m < v + eps){
                ans += FindAns(c + m / 2, Inval, p + m / 2, v, depth + 1, P * m);
            }else{
                ans += FindAns(c + v / 2, m - v, p + v / 2, v, depth + 1, P * m);
            }
        }
    }
    return ans + P * p * depth;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ld c, m, p, v;
    cin >> t;
    while(t--){
        cin >> c >> m >> p >> v;
        cout << fixed << setprecision(15) << FindAns(c, m, p, v, 1, 1) << '\n';
        //cout << cnt << endl;
    }
    return 0;
}