#include<iostream>
using namespace std;

const int MAX_A = 1010;
int PreSum[MAX_A][MAX_A];
char c;
int Ar, Ac, Tr, Tc;
//[1, Ar] [1, Ac]
int Min;

int GetSum(int U, int L, int D, int R){
    return PreSum[D][R] - PreSum[D][L - 1] - PreSum[U - 1][R] + PreSum[U - 1][L - 1];
}

void Test(int x, int y){
    int cnt = 0;
    int u, l, d, r;
    for(int i = x - Tr; i <= Ar; i += Tr){
        for(int j = y - Tc; j <= Ac; j += Tc){
            u = i;
            l = j;
            d = i + Tr - 1;
            r = j + Tc - 1;
            if(u < 1){
                u = 1;
            }
            if(l < 1){
                l = 1;
            }
            if(d > Ar){
                d = Ar;
            }
            if(r > Ac){
                r = Ac;
            }

            if(GetSum(u, l, d, r)){
                cnt++;
            }
        }
    }
    if(cnt < Min){
        Min = cnt;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> Ar >> Ac >> Tr >> Tc){
        for(int i = 0; i < Ar; i++){
            for(int j = 0; j < Ac; j++){
                cin >> c;
                PreSum[i + 1][j + 1] = PreSum[i][j + 1] + PreSum[i + 1][j] - PreSum[i][j];
                if(c == 'X'){
                    PreSum[i + 1][j + 1]++;
                }
            }
        }
        Min = 1000000;
        for(int i = 1; i <= Tr; i++){
            for(int j = 1; j <= Tc; j++){
                Test(i, j);
            }
        }
        cout << Min << '\n';
    }
    return 0;
}