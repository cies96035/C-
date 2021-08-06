#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
const int INF = 0x3fffffff;
int t, n;
ll a, Max, sum;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        sum = 0;
        cin >> n;
        cin >> Max; n--;
        rep(i, 0, n){
            cin >> a;
            if(a * Max < 0){
                sum += Max;
                Max = a;
            }else if(Max < a){
                Max = a;
            }
        }
        sum += Max;
        cout << sum << '\n';
    }
    return 0;
}