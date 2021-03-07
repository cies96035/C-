#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int c[6] ={
        0, 0, 0, 1, 1, 1
    };
    int arr[6];
    int a, b;
    int sum;
    for(int i = 0; i < 6; i++)
        cin >> arr[i];
    cin >> a >> b;
    sort(arr, arr + 6, greater<int>());
    do{
        sum = 0;
        for(int i = 0; i < 6; i++){
            sum += c[i] * arr[i];
        }

        if(sum == a){

            for(int i = 0; i < 6; i++){
                if(c[i]){
                    cout << arr[i] << ' ';
                }
            }

            int flg = 3;
            for(int i = 0; i < 6; i++){
                if(!c[i]){
                    cout << arr[i];
                    flg--;
                    
                    if(flg){
                        cout << ' ';
                    }else{
                        cout <<'\n';
                    }
                }

            }
            break;
        }
    }while(next_permutation(c, c + 6));
    
    return 0;
}