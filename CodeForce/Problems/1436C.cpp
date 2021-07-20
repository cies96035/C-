#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MOD = 1000000007;
int x, n, pos;
int gx, lx;
ll ans = 1;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> x >> pos;
    int Min = 0, Max = n, Mid;
    while(Min < Max){
        Mid = (Min + Max) >> 1;
        if(Mid > pos){
            Max = Mid;
            gx++;
        }else if(Mid < pos){
            Min = Mid + 1;
            lx++;
        }else{
            Min = Mid + 1;
            while(Min < Max){
                Mid = (Min + Max) >> 1;
                Max = Mid; 
                gx++;
            }
            break;
        }
    }
    for(int i = 0, j = x - 1; i < lx; i++, j--){
        ans *= j;
        ans %= MOD;
    }
    for(int i = 0, j = n - x; i < gx; i++, j--){
        ans *= j;
        ans %= MOD;
    }
    for(int i = n - lx - gx - 1; i > 0 ; i--){
        ans *= i;
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}