#include<iostream>
#include<iomanip>
using namespace std;
using ld = long double;

const int MAX_T = 500500;

ld ascentHieght[MAX_T];
ld descendHieght[MAX_T];
int aH, dH;

ld ascentSlope[MAX_T];
ld descendSlope[MAX_T];
int aS, dS;

int a, d;
int Height;
ld H, T, S;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> a >> d;

    ascentHieght[0] = 0;
    for(int i = 0; i < a; i++){
        cin >> H >> T;
        Height += H;
        S = H / T;
        while(T--){
            ascentSlope[aS] = S;
            ascentHieght[aS + 1] = ascentHieght[aS] + ascentSlope[aS];
            aS++;
        }
    }
    
    descendHieght[0] = Height;
    for(int i = 0; i < d; i++){
        cin >> H >> T;
        S = H / T;
        while(T--){
            descendSlope[dS] = S;
            descendHieght[dS + 1] = descendHieght[dS] - descendSlope[dS];
            dS++;
        }
    }

    for(int i = 0, end = min(aS, dS); i <= end; i++){
        if(ascentHieght[i] >= descendHieght[i]){
            i--;
            cout << fixed << setprecision(6) <<
            (descendHieght[i] - ascentHieght[i]) / (descendSlope[i] + ascentSlope[i]) + i << '\n';
            break;
        }
    }
    return 0;
}