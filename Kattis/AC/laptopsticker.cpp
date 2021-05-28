#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int wc, hc, ws, hs;
    
    cin >> wc >> hc >> ws >> hs;
    if(wc < ws + 2 || hc < hs + 2){
        cout << 0 << '\n';
    }else{
        cout << 1 << '\n';
    }
    return 0;
}