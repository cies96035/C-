#include<iostream>
using namespace std;

int h1, h2, h3;
int w1, w2, w3;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> h1 >> w1 >> h2 >> w2 >> h3 >> w3;
    if(h1 - w1 == w2 + w3 && h2 == h1 && h3 == h1){
        cout << "YES\n";
    }else if(h1 - w1 == h2 && h1 - w1 == h3 && h1 == w2 + w3){
        cout << "YES\n";
    }else if(h1 - w1 == w2 && h1 - w1 == h3 && h2 + w3 == h1){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}