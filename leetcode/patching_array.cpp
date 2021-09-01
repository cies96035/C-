#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
int minPatches(vector<int>& nums, int n) {
    bitset<10000005> bs;
    bs[0] = 1;
    int cnt = 0, k = 0;
    for(int i = 0; i < nums.size(); i++){
        bs |= bs << nums[i];
        while(k < nums[i]){
            if(!bs[k]){
                bs |= bs << k;
                cnt++;
            }
            k++;
        }
    }
    while(k < n){
        if(!bs[k]){
            bs |= bs << k;
            cnt++;
        }
        k++;
    }
    return cnt;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<int> vi;
    int n, t;
    cin >> t;
    while(t--){
        cin >> n;
        vi.emplace_back(n);
    }
    cin >> n;
    cout << minPatches(vi, n) << endl;;
    system("PAUSE");
    return 0;
}