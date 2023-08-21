#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

void f(){
    int x;
    ll sum = 0;
    int maxVal = 0;
    map<int, int> nums;
    rep(i, 0, 20) {
        cin >> x; 
        maxVal = max(maxVal, x);
        cout << "+ " << ((ll)rand() * RAND_MAX + rand()) % 100000000 << endl;
    }
    rep(i, 0, 980){
        cin >> x; 
        if(nums.count(x)){
            cout << "! " << sum - nums[x] << endl;
            return;
        }
        maxVal = max(maxVal, x);
        nums[x] = sum;
        if(i < 500){
            cout << "+ 1" << endl;
            sum++;
        }else if(i == 500){
            cout << "+ " << maxVal << endl;
            sum += maxVal;
        }else{
            cout << "+ 500" << endl;
            sum += 500;
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) f();
    
    return 0;
}