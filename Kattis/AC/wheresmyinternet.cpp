#include<iostream>
using namespace std;

const int MAX_N = 1000100;

int n, q;
char op;
int a, b;
int dSet[MAX_N];
bool isConnected = true;

void Init(int x){
    for(int i = 0; i < n; i++){
        dSet[i] = i;
    }
    return;
}
int Find(int x){
    return dSet[x] == x ? x : dSet[x] = Find(dSet[x]);
}
void Union(int a, int b){
    dSet[Find(a)] = dSet[Find(b)];
}
bool Same(int a, int b){
    return Find(a) == Find(b);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> q;
    Init(n + 1);
    while(q--){
        cin >> a >> b;
        Union(a, b);
    }
    for(int i = 2; i <= n; i++){
        if(!Same(1, i)){
            cout << i << '\n';
            isConnected = 0;
        }
    }
    if(isConnected){
        cout << "Connected\n";
    }
    return 0;
}