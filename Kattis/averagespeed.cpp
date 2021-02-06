#include<iostream>
#include<iomanip>
using namespace std;
using ld = long double;
#define ToNum(x) (x - '0')

ld StringToNum(string s){
    ld n = 0;
    for(auto c : s){
        n = 10 * n + ToNum(c);
    }
    return n;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string str;
    ld km = 0, kmps = 0;
    ld lh = 0, h;
    while(getline(cin, str)){
        h = ToNum(str[0]) * 10 + ToNum(str[1]) +
        ( ToNum(str[3]) * 10 + ToNum(str[4]) ) / 60.0 +
        ( ToNum(str[6]) * 10 + ToNum(str[7]) ) / 3600.0;
        km += (h - lh) * kmps;
        if(str.size() > 8){
            kmps = StringToNum(str.substr(9 , str.size() - 9));
        }else{
            cout << str << ' ' << fixed << setprecision(2) << km << " km\n";
        }
        lh = h;
    }
    
    return 0;
}