#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    int n;
    int arr[1000];
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            arr[i] = i + 1;
        }
        for(int i = 1; i < n; i += 2){
            swap(arr[i], arr[i - 1]);
        }
        if(n % 2){
            swap(arr[n - 1], arr[n - 3]);
        }
        for(int i = 0; i < n - 1; i++){
            cout << arr[i] << ' ';
        }
        cout << arr[n - 1] << '\n';
    }
    return 0;
}
/*
1234
2143
12345
21435
*/