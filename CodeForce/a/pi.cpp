#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 600;
struct G{
    vector<int> nums;
    int id, cost;
}group[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k, p;
    cin >> n >> k >> p;
    
    rep(i, 0, k){
        cin >> group[i].cost;
        group[i].id = 0;
    }
    int a, b;
    rep(i, 0, n){
        cin >> a >> b;
        group[b - 1].nums.emplace_back(a);
    }
    rep(i, 0, k){
        sort(group[i].nums.begin(), group[i].nums.end());
    }
    int sum = 0;
    rep(i, 0, k){
        int Min = 0x3fffffff, MinId = -1;
        rep(j, 0, n){
            
        }
    }
    return 0;
}