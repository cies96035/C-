#include<iostream>
using namespace std;

string S, E;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> S >> E;
    for(int i = 0; i < S.size() && i < E.size() && S[i] == E[i]; i++){
        S[i] = 'X';
        E[i] = 'O';
        cnt++;
    }
    for(int i = S.size() - 1, j = E.size() - 1; S[i] == E[j]; i--, j--){
        cnt++;
    }
    cout << E.size() - cnt << '\n';
    return 0;
}