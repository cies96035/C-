#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 200200;
int n;
int a[MAX_N];
int unRemoved[MAX_N], removed[MAX_N];
int Max = 0;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    cin >> a[0] >> a[1];
    removed[0] = unRemoved[0] = 1;
    unRemoved[1] = removed[1] = a[1] > a[0] ? 2 : 1;
    Max = unRemoved[1];
    rep(i, 2, n){
        cin >> a[i];
        if(a[i] <= a[i - 1]){
            if(a[i] > a[i - 2]){
                removed[i] = unRemoved[i - 2] + 1;
            }else{
                removed[i] = 1;
            }
            unRemoved[i] = 1;
        }else{
            if(a[i] > a[i - 2]){
                removed[i] = max(unRemoved[i - 2] + 1, removed[i - 1] + 1);
            }else{
                removed[i] = removed[i - 1] + 1;
            }
            unRemoved[i] = unRemoved[i - 1] + 1;
        }
        if(Max < removed[i]){
            Max = removed[i];
        }
    }
    cout << Max << '\n';
    return 0;
}