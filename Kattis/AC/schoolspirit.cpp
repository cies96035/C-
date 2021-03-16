#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
using ld = long double;

const int MAX_N = 55;

int n;
int arr[MAX_N];
ld avg;
ld Cnt(int x){
    ld sum = 0;
    ld b = 1;
    for(int i = n - 1; i >= 0; i--){
        if(i == x){
            continue;
        }
        sum += b * arr[i];
        b *= 0.8;
    }
    return sum / 5;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cout << fixed << setprecision(6);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for(int i = 0; i < n; i++){
        avg += Cnt(i);
    }
    cout << Cnt(-1) << '\n';
    cout << avg / n << '\n';
    return 0;
}