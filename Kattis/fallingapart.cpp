#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[20];
int player[2];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    for(int i = n - 1; i >= 0; i--){
        player[i & 1] += arr[i];
    }
    cout << player[0] << ' ' << player[1] << '\n';
    return 0;
}