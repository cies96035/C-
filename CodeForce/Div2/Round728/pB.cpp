#include<bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    const int MAX_N = 100100;
    int t, n;
    int ans;
    cin >> t;
    ll arr[MAX_N];
    while(t--){
        ans = 0;
        cin >> n;
        ld N = sqrt(2 * n) + 5;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        for(int i = 1; i <= n; i++){
            if(arr[i] < N){
                for(int j = 1; j <= n; j++){
                    if(i != j && arr[i] * arr[j] == i + j){
                        ans++;
                    }
                }
                arr[i] = -0x1fffffff;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}