#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, k;
vector<int> towers;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> k;
        if(towers.empty() || towers.back() <= k){
            towers.emplace_back(k);
        }else{
            *upper_bound(towers.begin(), towers.end(), k) = k;
        }
    }
    cout << towers.size() << '\n';
    return 0;
}