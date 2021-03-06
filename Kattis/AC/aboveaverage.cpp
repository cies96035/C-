#include<iostream>
#include<iomanip>
using namespace std;
using ld = long double;

const int MAX_N = 1010;

int C;
int N;
int arr[MAX_N];
ld n, sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cout << fixed << setprecision(3);
    cin >> C;
    while(C--){
        sum = n = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            sum += arr[i];
            arr[i] *= N;
        }
        for(int i = 0; i < N; i++){
            if(arr[i] > sum){
                n++;
            }
        }

        cout << n / N * 100 << "%\n";

    }
    return 0;
}