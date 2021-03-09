/*
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
using pii = pair<int, int>;

const int MAX_N = 1010;

set<pii> amount[MAX_N];
map<int, int> num;
int N, C;
int cnt;
int ipt;

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        cin >> ipt;
        num[i].first;
        if(!num[i].second){
            num[i].second = i;
        }
    }
    
    sort(num.begin(), num.end());
    for(int i = 1; i <= N; i++){
        cnt++;
        if(num[i].first != num[i - 1].first){
            amount[cnt].insert( pii(num[i - 1].second, num[i - 1].first) );
            cnt = 0;
        }
    }
    for(int i = MAX_N - 1; i >= 0; i--){
        for(auto j : amount[i]){
            for(int k = 0; k < i; k++){
                cout << j.second << ' ';
            }
        }
    }
    cout << endl;
    return 0;
}*/