#include<iostream>
using namespace std;

int P;
int N, K;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> P;
    while(P--){
        cin >> N >> K;
        cout << N << ' ';
        cout << ((K + 2) * (K + 1) / 2) - 1 << '\n';
    }
    return 0;
}
