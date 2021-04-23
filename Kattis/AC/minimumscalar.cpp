#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 850;

int T;
int n;
ll x[MAX_N], y[MAX_N];
ll sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    for(int Case = 1; Case <= T; Case++){
        sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        for(int i = 0; i < n; i++){
            cin >> y[i];
        }
        sort(x, x + n);
        sort(y, y + n, greater<int>());

        for(int i = 0; i < n; i++){
            sum += x[i] * y[i];
        }
        cout << "Case #" << Case << ": " << sum << '\n';
    }
    return 0;
}