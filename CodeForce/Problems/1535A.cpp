#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    int arr[4];
    int win[2];
    cin >> t;
    while(t--){
        for(int i = 0; i < 4; i++){
            cin >> arr[i];
            if(i & 1){
                win[i >> 1] = max(arr[i], arr[i - 1]);
            }
        }
        sort(arr, arr + 4);
        sort(win, win + 2);
        if(arr[2] == win[0] && arr[3] == win[1]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}