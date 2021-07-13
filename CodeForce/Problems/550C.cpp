#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

bool DP[1000];
string nums;
int tmp;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> nums;
    if(nums.find('0') != -1){
        cout << "YES\n0\n";
        return 0;
    }
    DP[0] = 1;
    for(auto c : nums){
        for(int i = 99; i >= 0; i--){
            if(DP[i]){
                DP[10 * i + c - '0'] = true;
            }
        }
    }
    for(int i = 8; i < 1000; i += 8){
        if(DP[i]){
            cout << "YES\n" << i << '\n';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}