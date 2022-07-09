#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 405;
int good[MAX_N][MAX_N]; // unsure :0 , good :1, bad :2
int surenum[MAX_N];
int n;
vector<int> num(int x, int y){

}
vector<pll> pickunsure(){
    vector<pll> tmp;
    bool flg;
    rep(i, 1, n){
        flg = true;
        rrep(j, i + 1, n){
            if(good[i][j] == 0){
                tmp.push_back({i, j});
                flg = false;
                break;
            }
        }
        if(flg)
            tmp.push_back({i, i + 1});
    }
    return tmp;
}
int query(vector<int> tmp){
    
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    vector<pll> tmp = pickunsure();
    while(query(tmp)){

    }
    return 0;
}