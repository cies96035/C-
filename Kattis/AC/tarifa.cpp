#include<iostream>
using namespace std;

int X, N, p;
int sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> X >> N;
    for(int i = 0; i < N; i++){
        cin >> p;
        sum -= p;
    }
    cout << X * (N + 1) + sum << '\n';
    return 0;
}