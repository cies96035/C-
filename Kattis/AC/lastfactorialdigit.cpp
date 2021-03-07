#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int F[11] ={
        1,1,2,6,4,0,0,0,0,0,0
    };
    int T;
    int N;
    cin >> T;
    while(T--){
        cin >> N;
        cout << F[N] << '\n';
    }
    return 0;
}