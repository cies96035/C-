#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_X = 1000005;
const int MAX_SX = 1001;
int n;
int x;
int t, cnt, ans;
int primeF[MAX_X];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    primeF[0] = primeF[1] = -1;
    for(int i = 2; i < MAX_X; i++){
        if(!primeF[i]){
            for(int j = i * i; i < MAX_SX && j < MAX_X; j += i){
                if(!primeF[j]){
                    primeF[j] = i;
                }
            }
            primeF[i] = i;
        }
    }
    cin >> n;
    while(n--){
        cin >> x;
        ans = 1;
        while(x != 1){
            cnt = 1;
            t = primeF[x];
            while(x % t == 0){
                x /= t;
                cnt++;
            }
            ans *= cnt;
        }
        cout << ans << '\n';
    }
    return 0;
}