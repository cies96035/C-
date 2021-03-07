#include<iostream>
using namespace std;

int N;
int a, b, c;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N--){
        cin >> a >> b >> c;

        if(a + b == c || a + c == b || b + c == a ||
        a * b == c || a * c == b || b * c == a){
            cout << "Possible\n";
        }else{
            cout << "Impossible\n";
        }
    }
    return 0;
}