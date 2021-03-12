#include<iostream>
using namespace std;

int n;
int s, d;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> s >> d;
        if(d > s || (s + d) & 1){
            cout << "impossible\n";
        }else{
            d++;
            cout << (s / 2 + d / 2) << ' ' << (s / 2 + d / 2 - d + 1) << '\n';
        }
    }
    return 0;
}