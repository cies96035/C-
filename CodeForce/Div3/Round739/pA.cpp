#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int arr[1100];
    for(int i = 1, id = 0; id < 1100; i++){
        if(!(i % 3 == 0 || i % 10 == 3)){
            arr[id++] = i;
        }
    }
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << arr[n - 1] << '\n';
    }
    return 0;
}