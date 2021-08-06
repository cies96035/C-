#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
int n;
int p[MAX_N];
ll test(int x){
    ll sum = 0;
    rep(i, 0, n){
        sum += abs(p[i] - x);
    }
    return sum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> p[i];
    }
    ll i = -1e9, j = 1e9, Mid;
    while(i < j){
        Mid = (i + j) / 2;
        if(test(Mid + 1) > test(Mid)){
            j = Mid;
        }else{
            i = Mid + 1;
        }
    }
    cout << test(i) << '\n';
    return 0;
}