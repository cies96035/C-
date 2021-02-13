#include<iostream>
#include<climits>
using namespace std;
using ld = long double;
ld Value(ld a, ld b, ld c){
    return (4 * a * c + b * b) / (4 * a);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t, n, maxValue, maxId;
    int a, b, c;
    cin >> t;
    while(t--){
        maxValue = INT_MIN;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a >> b >> c;
            if(maxValue < Value(a, b, c)){
                maxValue = Value(a, b, c);
                maxId = i;
            }
        }
        cout << maxId << '\n';
    }
    return 0;
}