#include<iostream>
using namespace std;

int n, m;
string a, b;
int tmpa, tmpb, key;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    cin >> a >> b;
    int shift = (26 + a.back() - b.back() - 'a') % 26;
    for(auto &i : a){
        i = (i - 'a') % 26;
    }
    for(auto &i : b){
        i = (i - 'a') % 26;
    }

    for(int i = b.size() - 1; i >= 0; i--){
        b[i] = (b[i] + key) % 26;
        tmpa = a.back();
        tmpb = b[i];
        key = (b[i] - a.back() + 26) % 26;
    }
    for(auto i : b){
        cout << char(i + 'a');
    }
    cout << '\n';
    
    return 0;
}