#include<iostream>
using namespace std;

const int MAX_N = 100;
int n;
string SET[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int Set = 1; cin >> n && n; Set++){
        for(int i = 0; i < n; i++){
            cin >> SET[i];
        }
        cout << "SET " << Set << '\n';
        for(int s = 0; s < n; s += 2){
            cout << SET[s] << '\n';
        }
        for(int e = n - 1 - (n & 1); e > 0; e -= 2){
            cout << SET[e] << '\n';
        }
    }
    return 0;
}