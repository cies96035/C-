#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    if(n % 4 == 0){
        cout << "YES\n" << n / 2 << '\n';
        for(int i = 1, j = n; i < j; i += 2, j -= 2){
            cout << i << ' ' << j << ' ';
        }
        cout << '\n' << n / 2 << '\n';
        for(int i = 2, j = n - 1; i < j; i += 2, j -= 2){
            cout << i << ' ' << j << ' ';
        }
        cout << '\n';
    }else if(n % 4 == 3){
        cout << "YES\n";
        cout << (n + 1) / 2 << '\n';
        cout << "1 2 ";
        for(int i = 4, j = n; i < j; i += 2, j -= 2){
            cout << i << ' ' << j << ' ';
        }
        cout << '\n' << n / 2 << '\n';
        cout << "3 ";
        for(int i = 5, j = n - 1; i < j; i += 2, j -= 2){
            cout << i << ' ' << j << ' ';
        }
    }else{
        cout << "NO\n";
    }
    return 0;
}