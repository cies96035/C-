#include<iostream>
#include<algorithm>
using namespace std;

string a, b;
int ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    ans = count(a.begin(), a.end(), 'S');
    ans *= count(b.begin(), b.end(), 'S');
    for(int i = 0; i < ans; i++){
        cout << "S(";
    }
    cout << '0';
    for(int i = 0; i < ans; i++){
        cout << ')';
    }
    cout << '\n';
    return 0;
}