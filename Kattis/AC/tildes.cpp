#include<iostream>
using namespace std;

const int MAX_N = 1000100;
int n, q, a, b;
char c;
int cnt[MAX_N];
int set[MAX_N];

void Init(){
    for(int i = 0; i < MAX_N; i++){
        set[i] = i;
        cnt[i]++;
    }
}

int find(int x){
    return set[x] == x ? x : set[x] = find(set[x]);
}

void Union(int a, int b){
    if(find(a) == find(b)){
        return;
    }
    cnt[find(a)] += cnt[find(b)];
    cnt[find(b)] = 0;
    set[find(b)] = find(a);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    Init();

    cin >> n >> q;
    while(q--){
        cin >> c;
        if(c == 't'){
            cin >> a >> b;
            Union(a, b);
        }else{
            cin >> a;
            cout << cnt[find(a)] << '\n';
        }
    }
    return 0;
}