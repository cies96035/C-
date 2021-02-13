#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;
const int MAX_N = 10010;
const int MAX_M = 50;
vector<int> m_ary;

ll value[MAX_M][MAX_N];
int P;
int K, m, n;

ll Solve(int i, int N){
    if(N < 0){
        return 0;
    }else if(N == 0){
        return 1;
    }else if(value[i][N] != -1){
        return value[i][N];
    }

    ll tmp = 0;
    for(int j = i; j < m_ary.size(); j++){
        tmp += Solve(j, N - m_ary[j]);
    }

    return value[i][N] = tmp;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> P;
    while(P--){
        memset(value, -1, sizeof(value));
        cin >> K >> m >> n;
        for(int i = 1; i < MAX_N; i *= m){
            m_ary.push_back(i);
        }
        cout << K << ' ' << Solve(0, n) << '\n';
        m_ary.clear();
    }
    return 0;
}