#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e5 + 5;
int t, n, ipt;
int a[MAX_N], b[MAX_N], bsum;
bool test(int x){
    int asum = a[n - 1] + 100 * x;
    if(n + x >= 4){
        asum -= a[(n + x) / 4 - 1];
    }

    int bsum = b[n - 1];
    if((n + x) / 4 > x){
        bsum -= b[(n + x) / 4 - x - 1];
    }
    //cout << x << ' ' << asum << ' ' << bsum << endl;
    return asum >= bsum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        
        rep(i, 0, n){
            cin >> a[i];
        }
        sort(a, a + n);
        rep(i, 1, n){
            a[i] += a[i - 1];
        }

        rep(i, 0, n){
            cin >> b[i];
        }
        sort(b, b + n);
        rep(i, 1, n){
            b[i] += b[i - 1];
        }

        int l = 0, r = n, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(test(mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }
    return 0;
}