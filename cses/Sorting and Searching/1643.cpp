#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, x;
ll sum, Max = -0x3fffffff;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> x;
        sum += x;
        if(sum > Max){
            Max = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    cout << Max << '\n';
    return 0;
}