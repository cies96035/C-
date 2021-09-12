#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, n;
    char c;
    int a[110];
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            a[i] = 0;
        }
        rep(i, 0, 3){
            rep(j, 0, 3 * n){
                cin >> c;
                if(c == '*'){
                    a[j / 3]++;
                }
            }
        }
        int Max = -1;
        rep(i, 0, n){
            Max = max(Max, a[i] * 4);
        }
        cout << Max << '\n';

    }
    return 0;
}