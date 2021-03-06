#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 100100;
int n;
int c[MAX_N];
int sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        sum += c[i];
    }
    sort(c, c + n);
    for(int i = n - 3; i >= 0; i -= 3){
        sum -= c[i];
    }
    cout << sum << '\n';
    return 0;
}