#include<iostream>
using namespace std;

int H, M;
int Time;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> H >> M;
    Time = H * 60 + M;
    Time += 1395;
    Time %= 1440;
    cout << Time / 60 << ' ' << Time % 60 << '\n';
    return 0;
}