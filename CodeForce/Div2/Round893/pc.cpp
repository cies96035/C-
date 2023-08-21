#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e5 + 5;
int vised[MAX_N], vid = 1;
int a[MAX_N], idx;
void f(){
    vid++;
    int n;
    cin >> n;
    idx = 0;
    rrep(i, 1, n){
        if(vised[i] != vid){
            int t = i;
            while(t <= n){
                vised[t] = vid;
                a[idx++] = t;
                cout << a[idx - 1] << ' ';
                t *= 2;
            }
        }
    }
    cout << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) f();
    
    return 0;
}
/*
7 3
11011010
221
111

*/