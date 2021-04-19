#include<bits/stdc++.h>
using namespace std;
using ld = long double;
const int MAX_N = 100100;

struct POINT{
    ld x, y;
};

bool cmpx (const POINT &a, const POINT &b){
    return a.x < b.x;
}
bool cmpy (const POINT &a, const POINT &b){
    return a.y < b.y;
}

int n;
POINT point[MAX_N];
POINT BA, BB;
ld dis;
ld tmpdis;

ld distance(const POINT &a, const POINT &b){
    ld dx = a.x - b.x;
    ld dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
void DaC(int l, int r){
    static int mid;
    static int a, b;
    if(r - l < 4){//暴力
        sort(point + l, point + r, cmpy);
        for(int i = l; i < r; i++){
            for(int j = i + 1; j < r; j++){
                if(dis > distance(point[i], point[j])){
                    dis = distance(point[i], point[j]);
                    BA = point[i];
                    BB = point[j];
                }
            }
        }
    }else{
        mid = (l + r) / 2;
        DaC(l, mid);
        DaC(mid, r);
        merge(point + l, point + mid, point + mid, point + r, point + l, cmpy);
        for(int i = l; i < r; i++){
            for(int j = 1; j <= 4 && i + j < r; j++){
                if(dis > distance(point[i], point[i + j])){
                    dis = distance(point[i], point[i + j]);
                    BA = point[i];
                    BB = point[j];
                }
            }
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n && n){
        dis = 10000000;
        for(int i = 0; i < n; i++){
            cin >> point[i].x >> point[i].y;
        }
        sort(point, point + n, cmpx);
        DaC(0, n);
        // for(int i = 0; i < n; i++){
        //     cout << point[i].y << ' ';
        // }
        // cout << endl;
        cout << BA.x << ' ' << BA.y << ' ' << BB.x << ' ' << BB.y << '\n';
    }
    return 0;
}