#include<iostream>
using namespace std;
using ull = unsigned long long;
const string numbers = "0123456789ACDEFHJKLMNPRTVWX";
const int Cd[8] = {2, 4, 5, 7, 8, 10, 11, 13};

int P;
int K;
int Map[256];
string fbi;

bool check(){
    ull sum = 0;
    for(int i = 0; i < 8; i++){
        sum += Map[ fbi[i] ] * Cd[i];
    }
    if(Map[ fbi[8] ] != sum % 27){
        return false;
    }else{
        return true;
    }
}

ull getNum(){
    ull n = 0;
    for(int i = 0; i < 8; i++){
        n = n * 27 + Map[ fbi[i] ];
    }
    return n;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < numbers.size(); i++){
        Map[numbers[i]] = i;
    }

    Map['B'] = Map['8'];
    Map['G'] = Map['C'];
    Map['I'] = Map['1'];
    Map['O'] = Map['Q'] = Map['0'];
    Map['S'] = Map['5'];
    Map['U'] = Map['Y'] = Map['V'];
    Map['Z'] = Map['2'];

    cin >> P;
    while(P--){
        cin >> K;
        cin >> fbi;
        cout << K << ' ';
        if(check()){
            cout << getNum() << '\n';
        }else{
            cout << "Invalid\n";
        }
    }
    return 0;
}