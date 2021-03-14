#include<iostream>
using namespace std;

int N;
int TB, LR;
int sw;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> sw;
        TB += !(sw / 1000);
        TB += !(sw / 100 % 10);
        LR += !(sw / 10 % 10);
        LR += !(sw % 10);
    }
    cout << min(TB, LR) / 2 << ' ' << TB - min(TB, LR) / 2 * 2 << ' ' << LR - min(TB, LR) / 2 * 2 << '\n';
    return 0;
}