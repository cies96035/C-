#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 100100;
int t;
int n;
int a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a;
        int Max = 0, cnt = 0;
        rep(i, 1, n){
            cin >> b;
            if(a > b){
                if(Max < a - b){
                    Max = a - b;
                }
                b = a;
            }
            a = b;
        }
        while(Max){
            cnt++;
            Max >>= 1;
        }
        cout << cnt << '\n';
    }
    return 0;
}