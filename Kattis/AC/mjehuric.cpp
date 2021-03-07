#include<iostream>
using namespace std;

int arr[5];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < 5; i++){
        for(int j = 1; j < 5; j++){
            if(arr[j - 1] > arr[j]){
                swap(arr[j - 1], arr[j]);
                for(int k = 0; k < 4; k++){
                    cout << arr[k] << ' ';
                }
                cout << arr[4] << '\n';
            }
        }
    }
    return 0;
}