#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 300300;
int q, n, k;
struct AirC{
    int pos;
    int cost;
    bool operator<(const AirC &x){
        return pos < x.pos;
    }
    AirC(){}
    AirC(int pos, int cost){
        this->pos = pos;
        this->cost = cost;
    }
}AC[MAX_N];

int dis(int a, int b){
    return abs(a - b);
}

int x;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> q;
    while(q--){
        cin >> n >> k;
        rep(i, 0, k){
            cin >> AC[i].pos;
        }
        rep(i, 0, k){
            cin >> AC[i].cost;
        }
        sort(AC, AC + k);

        //from left to right
        x = 0x3fffffff;
        rep(i, 0, k){
            if(AC[i].cost - AC[i].pos > x){
                AC[i].cost = x + AC[i].pos;
            }else{
                x = AC[i].cost - AC[i].pos;
            }
        }
        
        //from right to left
        x = 0x3fffffff;
        for(int i = k - 1; i >= 0; i--){
            if(AC[i].cost + AC[i].pos > x){
                AC[i].cost = x - AC[i].pos;
            }else{
                x = AC[i].cost + AC[i].pos;
            }
        }

        bool spaceFlg = false;
        for(int i = 1; i <= n; i++){
            if(spaceFlg){
                cout << ' ';
            }else{
                spaceFlg = true;
            }

            auto X = lower_bound(AC, AC + k, AirC(i, 0));
            auto D = X;
            if(X == AC){
                cout << X->cost + dis(X->pos, i);
            }else if(X == AC + k){
                X--;
                cout << X->cost + dis(X->pos, i);
            }else{
                D--;
                cout << min( dis(X->pos, i) + X->cost,
                             dis(D->pos, i) + D->cost);
            }
        }
        cout << '\n';
        
    }
    return 0;
}