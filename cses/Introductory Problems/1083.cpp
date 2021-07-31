#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i <= b; i++)

const int MAX_N = 200005;
bool used[MAX_N];
int n, ipt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 2, n){
        cin >> ipt;
        used[ipt] = true;
    }
    rep(i, 1, n){
        if(!used[i]){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}