#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 100100;
int n;
int ipt;
unordered_set<int> num;
map<int, ll> nums;
ll ans;
int two_power[31];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int b = 1;
    rep(i, 0, 31){
        two_power[i] = b;
        b <<= 1;
    }
    cin >> n;
    rep(i, 0, n){
        cin >> ipt;
        nums[ipt]++;
        num.insert(ipt);
    }
    for(auto i : num){
        for(auto j : two_power){
            if(i == j - i){
                ans += nums[i] * (nums[i] - 1) / 2;
            }else if(i < j - i){
                ans += nums[i] * nums[j - i];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}