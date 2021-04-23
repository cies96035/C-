#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MAX_N = 100100;

struct POINT{
    ll x, y;
};

bool cmpx (const POINT &a, const POINT &b){
    return a.x < b.x;
}
bool cmpy (const POINT &a, const POINT &b){
    return a.y < b.y;
}

int n;
POINT point[MAX_N], tmp[MAX_N];
POINT BA, BB;
ll dis;
ld iptA, iptB;

ll distance(const POINT &a, const POINT &b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}
void DaC(int l, int r){
    int mid, idx;
    if(r - l < 4){//force
        for(int i = l; i < r; i++){
            for(int j = i + 1; j < r; j++){
                if(dis > distance(point[i], point[j])){
                    dis = distance(point[i], point[j]);
                    BA = point[i];
                    BB = point[j];
                }
            }
        }
        sort(point + l, point + r, cmpy);
    }else{
        idx = l;
        mid = (l + r) / 2;
        int mx = point[mid].x;
        DaC(l, mid);
        DaC(mid, r);
        for(int i = l; i < r; i++){
            if(mx - dis <= point[i].x && point[i].x <= mx + dis){
                swap(point[idx++], point[i]);
            }
        }

        sort(point + l, point + idx, cmpy);
        
        for(int i = l; i < idx; i++){
            for(int j = i + 1; j < idx && point[j].y - point[i].y < dis; j++){
                if(dis > distance(point[i], point[j])){
                    dis = distance(point[i], point[j]);
                    BA = point[i];
                    BB = point[j];
                }
            }
        }
        // idx = mid;
        // for(int i = l; i < mid; i++){
        //     idx = lower_bound(point + idx, point + r, point[i], cmpy) - point;
        //     for(int j = 0; j <= 3 && idx + j < r; j++){
        //         if(dis > distance(point[i], point[idx + j])){
        //             dis = distance(point[i], point[idx + j]);
        //             BA = point[i];
        //             BB = point[idx + j];
        //         }
        //     }
        // }

        // idx = l;
        // for(int i = mid; i < r; i++){
        //     idx = lower_bound(point + idx, point + mid, point[i], cmpy) - point;
        //     for(int j = 0; j <= 3 && idx + j < r; j++){
        //         if(dis > distance(point[i], point[idx + j])){
        //             dis = distance(point[i], point[idx + j]);
        //             BA = point[i];
        //             BB = point[idx + j];
        //         }
        //     }
        // }
        
        // inplace_merge(point + l, point + mid, point + r, cmpy);
    }
}

void llTold(ll x, bool opinion){
    cout << x / 100 << '.' << setw(2) << setfill('0') << abs(x % 100);
    if(opinion){
        cout << ' ';
    }else{
        cout << '\n';
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n && n){
        dis = 1e18;
        for(int i = 0; i < n; i++){
            cin >> iptA >> iptB;
            point[i].x = round(100 * iptA);
            point[i].y = round(100 * iptB);
        }
        sort(point, point + n, cmpx);
        DaC(0, n);
        llTold(BA.x, 1);
        llTold(BA.y, 1);
        llTold(BB.x, 1);
        llTold(BB.y, 0);
    }
    return 0;
}