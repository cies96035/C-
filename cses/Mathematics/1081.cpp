#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1e6 + 5;
int n, x;
int nums[MAX_N], Max = 0, cnt;
int findGCD(){
    for(int i = Max; i > 0; i--){
        cnt = 0;
        for(int j = i; j < MAX_N; j += i){
            cnt += nums[j];
        }
        if(cnt >= 2){
            return i;
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> x;
        nums[x]++;
        if(x > Max){
            Max = x;
        }
    }
    cout << findGCD() << '\n';
    return 0;
}