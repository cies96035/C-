#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t;
int n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int arr[200200];
    cin >> t;
    while(t--){
        cin >> n;
        cin >> arr[0];
        cout << 0;
        rep(i, 1, n){
            cin >> arr[i];
            cout << ' ' << (arr[i] | arr[i - 1]) - arr[i];
            arr[i] = (arr[i] | arr[i - 1]);
        }
        cout << '\n';
    }
    return 0;
}