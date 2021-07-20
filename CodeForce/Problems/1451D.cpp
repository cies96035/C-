#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, a, b) for(int i = a; i < b; i++)


const ld eps = 1e-8;

int t;
ld d, k;
ll p;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> d >> k;
        d /= k;
        d += eps;
        p = d / sqrt(2) + eps;
        if(p * p + (p + 1) * (p + 1) <= d * d){
            cout << "Ashish\n";
        }else{
            cout << "Utkarsh\n";
        }
    }
    return 0;
}