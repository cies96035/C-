#include<bits/stdc++.h>
using namespace std;

set<int> hotdog_dp;
set<int> bun_dp;
map<int, int> hotdog_mincost;
map<int, int> bun_mincost;
int ans = 0x3FFFFFFF;

void sol(vector<int> &arr, set<int> &dp, map<int, int> &mincost){
    sort(arr.begin(), arr.end(), greater<int>());
    for(auto i : arr){
        for(auto j = dp.rbegin(); j != dp.rend(); j++){
            if(!dp.count(i + *j)){
                mincost[i + *j] = mincost[*j] + 1;
                dp.insert(i + *j);
            }
        }
        if(!dp.count(i)){
            dp.insert(i);
            mincost[i] = 1;
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int H, B;
    cin >> H;
    vector<int> dog(H);
    for(int i = 0; i < H; i++){
        cin >> dog[i];
    }
    sol(dog, hotdog_dp, hotdog_mincost);

    
    cin >> B;
    vector<int> bun(B);
    
    for(int i = 0; i < B; i++){
        cin >> bun[i];
    }
    sol(bun, bun_dp, bun_mincost);
    
    // for(auto i : bun_mincost){
    //     cout << i.first << ' ' << i.second << endl;
    // }
    while(!hotdog_dp.empty() && !bun_dp.empty()){
        auto a = hotdog_dp.begin(), b = bun_dp.begin();

        if(*a == *b){
            ans = min(ans, hotdog_mincost[*a] + bun_mincost[*b]);
        }
        if(*a < *b){
            hotdog_dp.erase(a);
        }else{
            bun_dp.erase(b);
        }
    }
    if(ans == 0x3FFFFFFF){
        cout << "impossible\n";
    }else{
        cout << ans << '\n';
    }
    return 0;
}