#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5;
int n, cnt, Max;
int a[MAX_N], b[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);

    int j = 0;
    rep(i, 0, n){
        while(b[j] < a[i]){
            cnt--;
            j++;
        }
        cnt++;
        if(cnt > Max){
            Max = cnt;
        }
    }
    cout << Max << '\n';
    return 0;
}