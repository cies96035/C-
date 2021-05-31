#include<bits/stdc++.h>
using namespace std;

int arr[3];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 3; i++){
        cin >> arr[i];
    }
    sort(arr, arr + 3);
    if(arr[0] == arr[1]){
        cout << arr[2] << '\n';
    }else if(arr[1] == arr[2]){
        cout << arr[0] << '\n';
    }else{
        cout << "0\n";
    }
    return 0;
}