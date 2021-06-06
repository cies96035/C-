#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2020;
vector<int> road[MAX_N];
int N, M, A, B;
int vised[MAX_N], visId;
int x;
ll sum;
ll DFS(int s){
    if(vised[s] == visId){
        return 0;
    }
    vised[s] = visId;
    ll cnt = 1;
    for(auto e : road[s]){
        cnt += DFS(e);
    }
    return cnt;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        road[A].emplace_back(B);
    }
    for(int i = 1; i <= N; i++){
        visId = i;
        sum += DFS(i);
    }
    cout << sum << '\n';
    return 0;
}