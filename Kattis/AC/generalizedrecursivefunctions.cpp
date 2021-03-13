#include<iostream>
#include<iomanip>
#include<sstream>

using namespace std;
using ull = unsigned long long;

const ull MOD = 1000000000000000000; // 10^18
const ull DIGIT_WIDTH = 18;

const int MAX_RNG = 105;
const int MAX_AB = 21;
const int MAX_DIGIT_SIZE = 3;

int usedId;

struct BIGNUM{
    ull dig[MAX_DIGIT_SIZE];
    int used;

    inline void Init(ull x){
        for(int i = 0; i < MAX_DIGIT_SIZE; i++){
            dig[i] = 0;
        }
        used = usedId;
        dig[0] = x;
    }

    inline void operator += (const BIGNUM x){
        for(int i = 0; i < MAX_DIGIT_SIZE; i++){
            dig[i] += x.dig[i];
            if(dig[i] >= MOD){
                dig[i + 1] += dig[i] / MOD;
                dig[i] -= MOD;
            }
        }
    }

    inline void PRINT(){
        bool prezero = false;
        for(int i = 2; i >= 0; i--){
            if(prezero){
                cout << setw(DIGIT_WIDTH) << dig[i];
            }else if(dig[i] != 0){
                cout << dig[i];
                prezero = true;
            }
        }
        if(!prezero){
            cout << 0;
        }
        cout << '\n';
    }
}DP[MAX_RNG][MAX_RNG];

string iptStr;
int n;
int a, b;
int A[MAX_AB], B[MAX_AB], abSize;
ull c;
BIGNUM d;

void RE(int x, int y){
    int nx, ny;
    if(x > 0 && y > 0){
        DP[x][y].Init(c);
        for(int i = 0; i < abSize; i++){
            nx = x - A[i], ny = y - B[i];
            if(nx <= 0 || ny <= 0){
                DP[x][y] += d;
            }else if(DP[nx][ny].used == usedId){
                DP[x][y] += DP[nx][ny];
            }else{
                RE(nx, ny);
                DP[x][y] += DP[nx][ny];
            }
        }
    }else{
        DP[x][y] = d;
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cout << setfill('0');

    cin >> n;
    cin.ignore();

    while(n--){
        usedId++;
        abSize = 0;

        getline(cin, iptStr);
        stringstream ss(iptStr);
        while(ss >> A[abSize] >> B[abSize]){
             abSize++;
        }
        abSize--;
        c = A[abSize];
        d.Init( B[abSize] );

        getline(cin, iptStr);
        stringstream ss2(iptStr);

        while(ss2 >> a >> b){
            RE(a, b);
            DP[a][b].PRINT();
        }

        cout << '\n';
    }

    return 0;
}