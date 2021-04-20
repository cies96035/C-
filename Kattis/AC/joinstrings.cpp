#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100100;

int N;
string S[MAX_N];
list<int> L[MAX_N];
int a = 1, b;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> S[i];
        L[i].push_back(i);
    }
    for(int i = 1; i < N; i++){
        cin >> a >> b;
        L[a].splice(L[a].end(), L[b]);
    }
    for(auto i : L[a]){
        cout << S[i];
    }
    cout << '\n';

    return 0;
}