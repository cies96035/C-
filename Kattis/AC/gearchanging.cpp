#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

const ll MAX_NM = 101;

ll N, M, P, gearId;
struct GEAR{
    ll c;
    ll d;
    bool operator < (GEAR x){
        return x.d * c < x.c * d;
    }
}gear[MAX_NM * MAX_NM];
ll C[MAX_NM];
ll D[MAX_NM];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M >> P;
    for(int i = 0; i < N; i++){
        cin >> C[i];
    }
    for(int i = 0; i < M; i++){
        cin >> D[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            gear[gearId].c = C[i];
            gear[gearId++].d = D[j];
        }
    }
    N *= M;
    P += 100;
    sort(gear, gear + N);
    
    for(int i = 1; i < N; i++){
        // gear[i] / gear[i - 1] > P%
        if(100 * gear[i].c * gear[i - 1].d > P * gear[i - 1].c * gear[i].d){
            cout << "Time to change gears!\n";
            return 0;
        }
    }
    cout << "Ride on!\n";
    return 0;
}