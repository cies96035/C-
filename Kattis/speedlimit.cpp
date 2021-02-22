#include<iostream>
using namespace std;

int n;
int sum, s, t, h;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n && n != -1){
        h = 0;
        sum = 0;
        while(n--){
            cin >> s >> t;
            sum += s * (t - h);
            h = t;
        }
        cout << sum << " miles\n";
    }
    
    
    return 0;
}