#include<iostream>
using namespace std;

int N;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    if(N & 1){
        cout << "Either\n";
    }else{
        if((N / 2) & 1){
            cout << "Odd\n";
        }else{
            cout << "Even\n";
        }
    }
    return 0;
}