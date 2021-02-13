#include<iostream>
using namespace std;

int l, w;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> l >> w;
    if(w < l || w > 26 * l){
        cout << "impossible\n";
    }else{
        for(int i = l; i > 0; i--){
            cout << char(w / i + 'a' - 1);
            w -= w / i;
        }
        cout << '\n';
    }
    return 0;
}