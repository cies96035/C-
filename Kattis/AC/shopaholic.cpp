#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 200200;
int n;
int p[MAX_N];
ll sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p, p + n);
    for(int i = n - 3; i >= 0; i -= 3){
        sum += p[i];
    }
    cout << sum << '\n';
    return 0;
}