#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n;
ll cnt = 0;
int Max, x;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    Max = -0x3fffffff;
    cin >> n;
    while(n--){
        cin >> x;
        if(x < Max){
            cnt += Max - x;
        }else{
            Max = x;
        }
    }
    cout << cnt << '\n';
    return 0;
}