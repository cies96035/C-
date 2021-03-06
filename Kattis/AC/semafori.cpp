#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 110;
struct TrafficLight{
    int D;
    int R;
    int G;
}light[MAX_N];

int N, L;
int Time, t, tt;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> L;
    for(int i = 1; i <= N; i++){
        cin >> light[i].D >> light[i].R >> light[i].G;
    }
    for(int i = 1; i <= N; i++){
        t = light[i].R + light[i].G;
        Time += light[i].D - light[i - 1].D;
        tt = Time % t;
        if(tt < light[i].R){
            Time += light[i].R - tt;
        }
    }
    cout << Time + L - light[N].D << '\n';
    return 0;
}