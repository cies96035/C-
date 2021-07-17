#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, k;
int a[100];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    k--;
    while(k + 1 < n && a[k] == a[k + 1]){
        k++;
    }
    while(k >= 0 && a[k] == 0){
        k--;
    }
    k++;
    cout << k << '\n';
    return 0;
}