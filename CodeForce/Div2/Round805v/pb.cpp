#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5;
int arr[MAX_N];
int n;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--){
        set<int> nums;
        cin >> n;
        int idx = 0;
        rrep(i, 1, n){
            int tmp = i;
            if(nums.count(tmp))continue;
            while(tmp <= n){
                arr[idx++] = tmp;
                nums.insert(tmp);
                tmp *= 2;
            }
        }
        cout << 2 << '\n';
        rep(i, 0, n){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}