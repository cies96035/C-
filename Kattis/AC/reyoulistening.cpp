#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
using ld = long double;

const int MAX_N = 1100;
int x, y, n;
int dx, dy, dr;
ld arr[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> x >> y >> n;
    for(int i = 0; i < n; i++){
        cin >> dx >> dy >> dr;
        dx -= x;
        dy -= y;
        arr[i] = sqrt(dx * dx + dy * dy) - dr;
    }
    sort(arr, arr + n);
    cout << max((int)arr[2], 0)  << '\n';
    return 0;
}