#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
bitset<1000005> bs;
int minPatches(vector<int>& nums, ll n) {
    bs[0] = 1;
    ll cnt = 0, k = 0, sum = 0;
    for(ll i = 0; i < nums.size(); i++){
        bs |= bs << nums[i];
        sum += nums[i];
    }
    while(bs[k] == 1 && k <= n){
        k++;
    }
    while(k <= n){
        // cout << k << endl;
        k <<= 1;
        cnt++;
    }
    cout << k << endl;
    return cnt;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<int> vi(10000, 1000);
    cout << '[';
    for(int i = 0; i < 1000; i++){
        cout << 10000 << ',';
    }
    cout << ']' << endl;
    int n, t;
    // cin >> t;
    // while(t--){
    //     cin >> n;
    //     vi.emplace_back(n);
    // }
    // for(int i = 0; i < 10000; i++){

    // }
    cin >> n;
    cout << minPatches(vi, n) << endl;
    return 0;
}
/*
83
1 2 3 6 7 7 7 8 10 11 11 11 12 15 17 17 18 19 20 23 24 24 26 28 29 30 30 31 31 32 33 34 36 37 37 41 44 48 51 54 59 61 62 62 63 64 64 64 65 66 67 68 71 71 71 72 75 75 76 77 79 80 80 80 81 82 82 84 85 86 87 90 90 91 92 92 92 93 96 97 97 98 100
16
*/
/*
[1,2,3,6,7,7,7,8,10,11,11,11,12,15,17,17,18,19,20,23,24,24,26,28,29,30,30,31,31,32,33,34,36,37,37,41,44,48,51,54,59,61,62,62,63,64,64,64,65,66,67,68,71,71,71,72,75,75,76,77,79,80,80,80,81,82,82,84,85,86,87,90,90,91,92,92,92,93,96,97,97,98,100]
16
*/