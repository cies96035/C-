#include<bits/stdc++.h>
using namespace std;
using ld = long double;

int n;
int l;
int lanterns[1000];
int Max = 0;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> lanterns[i];
    }
    sort(lanterns, lanterns + n);
    for(int i = 1; i < n; i++){
        if(lanterns[i] - lanterns[i - 1] > Max){
            Max = lanterns[i] - lanterns[i - 1];
        }
    }
    Max = max(Max, max(lanterns[0] * 2, (l - lanterns[n - 1]) * 2));
    cout << fixed << setprecision(10) << ld(Max) / 2 << '\n';
    return 0;
}