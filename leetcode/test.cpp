#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 100;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, cnt = 0;
    cin >> n;
    rep(i, 0, n){
        rep(j, i, n){
            rep(k, j, n){
                rep(l, k, n){
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}