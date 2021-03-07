#include<iostream>
using namespace std;

const int MAX_N = 100100;
int arr[MAX_N];
int n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = n - 1; i >= 0; i--){
        cout << arr[i] << '\n';
    }
    return 0;
}