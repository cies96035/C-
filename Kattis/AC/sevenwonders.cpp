#include<iostream>
using namespace std;

char c;
int T, C, G;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> c){
        if(c == 'T'){
            T++;
        }else if(c == 'C'){
            C++;
        }else{
            G++;
        }
    }
    cout << T * T + C * C + G * G + min(T, min(G, C)) * 7 << '\n';
    return 0;
}