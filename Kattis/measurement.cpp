#include<iostream>
#include<map>
#include<iomanip>
using namespace std;
using ld = long double;
map<string, ld> unit;

ld v;
string a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    unit["thou"] = unit["th"] = 1;
    unit["inch"] = unit["in"] = 1000;
    unit["foot"] = unit["ft"] = 12 * unit["in"];
    unit["yard"] = unit["yd"] = 3 * unit["ft"];
    unit["chain"] = unit["ch"] = 22 * unit["yd"];
    unit["furlong"] = unit["fur"] = 10 * unit["ch"];
    unit["mile"] = unit["mi"] = 8 * unit["fur"];
    unit["league"] = unit["lea"] = 3 * unit["mi"];
    
    cin >> v >> a >> b >> b;
    cout << fixed << setprecision(10) << v * unit[a] / unit[b] << '\n';
    return 0;
}