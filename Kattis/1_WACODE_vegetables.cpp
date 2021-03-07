#include<iostream>
#include<cmath>
using namespace std;
using ld = long double;

const int MAX_N = 1010;

ld T;
int N;
ld vegtable[MAX_N];
ld sumW;

bool Test(int x){
    ld avg = sumW / x;
    ld higher = 2 * avg / (1 + T) ;
    ld lower = higher * T ;
    ld l, h;
    int lowAmount = 0, highAmount = 0;
    for(int i = 0; i < N; i++ ){
        l = ceil(vegtable[i] / higher + 0.0001);
        h = floor(vegtable[i] / lower - 0.0001);
        if(l > h){
            return false;
        }
        lowAmount += l;
        highAmount += h;
    }
    if(lowAmount <= x && x <= highAmount){
        return true;
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T >> N;
    for(int i = 0; i < N; i++){
        cin >> vegtable[i];
        sumW += vegtable[i];
    }

    int k;
    for(k = 0; !Test(k + N); k++);

    cout << k << '\n';
    return 0;
}