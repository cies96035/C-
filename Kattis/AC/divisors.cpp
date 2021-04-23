#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int MAX_P = 450;
const int MAX_T = 11100;

int n, k;
map<int, int> Cnt[MAX_T];
vector<int> Prime;
int Div[MAX_P];
int tmp;
ull sum;

void CntAndAdd(int x, int Case, bool n){
    while(x != 1){
        if(n){
            Cnt[Case][Div[x]]++;
        }else{
            Cnt[Case][Div[x]]--;
        }
        x /= Div[x];
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 2; i < MAX_P; i++){
        for(int j = 2; j <= i; j++){
            if(i % j == 0){
                if(i == j){
                    Prime.push_back(i);
                }
                Div[i] = j;
                break;
            }
        }
    }

    for(int Case = 0; cin >> n >> k; Case++){
        for(int i = n - k + 1; i <= n; i++){
            CntAndAdd(i, Case, true);
        }
        for(int i = 2; i <= k; i++){
            CntAndAdd(i, Case, false);
        }
        sum = 1;
        for(auto i : Cnt[Case]){
            sum *= i.second + 1;
        }
        cout << sum << '\n';
    }
    return 0;
}