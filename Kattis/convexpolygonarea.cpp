#include<iostream>
using namespace std;

const int MAX_M = 200;
struct POINT{
    int x;
    int y;
}point[MAX_M];

int n, m;
int sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> point[i].x >> point[i].y;
        }
        sum = point[m - 1].x * point[0].y - point[m - 1].y * point[0].x;

        for(int i = 1; i < m; i++){
            sum += point[i - 1].x * point[i].y - point[i].x * point[i - 1].y;
        }

        cout << sum / 2.0 << '\n';
    }
    return 0;
}
/*
*/