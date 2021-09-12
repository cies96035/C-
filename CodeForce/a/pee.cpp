#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 4005;
ll Time;
struct SEG{
    bool vh;//v true, h false
    ll a1, a2, b;//h : (a1, b) ~ (a2, b), v : (b, a1) ~ (b, a2)
    ll t;
}seg[MAX_N];
bool inter(const SEG &x, const SEG &y){
    if(x.vh == y.vh){
        return x.b == y.b && x.a1 == y.a2;
    }
    int xa1 = x.a1, xa2 = x.a2, ya1 = y.a1, ya2 = y.a2;
    if(xa1 > xa2){
        swap(xa1, xa2);
    }
    if(ya1 > ya2){
        swap(ya1, ya2);
    }
    return xa1 <= y.b && y.b <= xa2 && ya1 <= x.b && x.b <= ya2;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, aed, bed, a, b;
    ll ans = 0x3fffffff;
    Time = 0;
    cin >> n >> aed >> bed;
    rep(i, 1, n){
        cin >> a >> b;
        if(b == bed){ // h
            seg[i].vh = false;
            seg[i].a1 = aed;
            seg[i].a2 = a;
            seg[i].b = b;
            seg[i].t = Time;
            Time += abs(a - aed);
        }else{
            seg[i].vh = true;
            seg[i].a1 = bed;
            seg[i].a2 = b;
            seg[i].b = a;
            seg[i].t = Time;
            Time += abs(b - bed);
        }
        // cout << i << ' ' << seg[i].vh << endl;
        for(int j = i - 2; j >= 0; j--){
            if(inter(seg[j], seg[i])){
                // cout << 'a' << i << ' ' << j << endl;
                if(seg[i].vh == seg[j].vh){
                    ans = min(ans, (Time - seg[j].t) );
                }else{
                    ans = min(
                        ans, 
                        ( abs(seg[i].a1 - seg[j].b) + seg[i].t ) - 
                        ( abs(seg[j].a1 - seg[i].b) + seg[j].t )
                    );
                }
            }
        }
        aed = a, bed = b;
    }
    cout << min(ans, Time) << '\n';
    
    return 0;
}