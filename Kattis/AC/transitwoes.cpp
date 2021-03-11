#include<iostream>
using namespace std;

const int MAX_N = 30;
int s, t, n;
int d[MAX_N];
int b[MAX_N];
int c[MAX_N];
int Time;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> s >> t >> n;
    for(int i = 0; i <= n; i++){
        cin >> d[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    Time = s + d[0];
    for(int i = 0; i < n; i++){
        if(Time % c[i]){
            Time = c[i] * (Time / c[i] + 1);
        }
        Time += b[i] + d[i + 1];
    }
    if(Time <= t){
        cout << "yes\n";
    }else{
        cout << "no\n";
    }
    return 0;
}