#include<iostream>
using namespace std;

const string weekDay[7] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};
const int monthDay[12] = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};
int D, M, cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> D >> M;
    D--;
    M--;
    for(int i = 0; i < M; i++){
        cnt += monthDay[i];
    }
    cout << weekDay[((cnt + D + 3) % 7)] << '\n';
    return 0;
}