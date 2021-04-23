#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 2020;
int n;
int w[MAX_N];
int Max[MAX_N][MAX_N];
int Min[MAX_N][MAX_N];
int L[MAX_N][MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w[i];
        Min[0][i] = Min[i][0] = 10000;
        L[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(L)
            if(w[j] > Max[i][j]){
                Max[i][j + 1] = w[j];
            }else if(w[j] < Min[i][j]){
                Min[i][j + 1] = w[j];
            }
        }
    }
    return 0;
}