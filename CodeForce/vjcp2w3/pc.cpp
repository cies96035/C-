#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)
typedef complex<int> Point;
typedef complex<int> Vector;
struct seg{
    Point s, e;
    Vector v;
    seg(){}
    seg(int a, int b, int c, int d){
        s = {a, b};
        e = {c, d};
        v = e - s;
    }
}L[5];
int cross(Vector a, Vector b){
    return (conj(a) * b).imag();
}
int cross(Point a, Point b, Point c){
    return (conj(a - b) * (c - b)).imag();
}
bool inter(seg a, seg b){
    int a = cross(b.v, a.s - b.s);
    int b = cross(a.v, a.s - b.s);
    int c = cross(a.v, b.v);
    if(c == 0){
        return a == b && a == 0;
    }
    return f(a.s.real(), a.e.real(), b.s.real(), b.e.real()) && 
    f(a.s.imag(), a.e.imag(), b.s.imag(), b.e.imag()) &&
    cross(a.s, a.e, b.s) * cross(a.s, a.e, b.e) <= 0 &&
    cross(b.s, b.e, a.s) * cross(b.s, b.e, a.e) <= 0;
}
int T;
int p[8];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> T;
    while(T--){
        rep(i, 0, 8){
            cin >> p[i];
        }
        L[0] = seg{p[4], p[5], p[6], p[5]};
        L[1] = seg{p[4], p[7], p[6], p[7]};
        L[2] = seg{p[4], p[5], p[4], p[7]};
        L[3] = seg{p[6], p[5], p[6], p[7]};
        L[4] = seg{p[0], p[1], p[2], p[3]};
        // rep(i, 0, 5){
        //     cout << L[i].s.real() << ' ' << L[i].s.imag() << ' ' << L[i].e.real() << ' ' << L[i].e.imag() << endl;
        // }
        if(inter(L[4], L[0]) || inter(L[4], L[1]) || inter(L[4], L[2]) || inter(L[4], L[3])){
            cout << "T\n";
        }else{
            cout << "F\n";
        }
    }
    return 0;
}

/*
1
4 9 11 2 3 8 20 6
*/