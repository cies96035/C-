#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
using ld = long double;

const int MAX_A = 31;
ld aLen[MAX_A];
ld sum;
int n;
int sheetAmount[MAX_A];
int sheetSize[MAX_A];

void Init(){
    for(int i = 0; i < MAX_A; i++){
        aLen[i] = 2 * ( pow(2, -(i * 2 - 1) / 4.0) + pow(2, -(i * 2 + 1) / 4.0) );
    }
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    Init();
    sum = -aLen[1];

    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> sheetAmount[i];
    }

    sheetSize[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        sheetSize[i] = 2 * sheetSize[i + 1];
    }

    for(int i = 2; i <= n; i++){
        if(sheetSize[1] > sheetAmount[i] * sheetSize[i]){
            sheetSize[1] -= sheetAmount[i] * sheetSize[i];
            sum += sheetAmount[i] * aLen[i];
        }else{
           sum += (sheetSize[1] / sheetSize[i]) * aLen[i];
           sheetSize[1] -= (sheetSize[1] / sheetSize[i]);
           break;
        }
    }
    if(sheetSize[1]){
        cout << "impossible\n";
    }else{
        cout << fixed << setprecision(10) << sum / 2 << '\n';
    }
    return 0;
}