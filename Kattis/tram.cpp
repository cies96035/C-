#include<iostream>
using namespace std;
using ll = long long;

int N;
int x, y;
ll sum;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        sum += y - x;
    }
    cout << sum / (long double)N << '\n';
    
    return 0;
}