#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int t, n;
int arr[1000];
void f(int i){
    while(i + 1 < n){
        if(arr[i] > arr[i + 1]){
            swap(arr[i], arr[i + 1]);
        }
        i += 2;
    }
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> arr[i];
        }
        int k = 0;
        bool flg = true;
        while(flg){
            // cout << arr[0] << ' ';
            for(int i = 1; i < n; i++){
                // cout << arr[i] << ' ';
                if(arr[i] < arr[i - 1]){
                    break;
                }
                if(i == n - 1){
                    flg = false;
                }
            }
            // cout << k << endl;
            // cout << endl;
            f(k & 1);
            k++;
        }
        cout << k - 1 << '\n';
    }
    return 0;
}