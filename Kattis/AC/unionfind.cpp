#include<iostream>
using namespace std;
using ull = unsigned long long;

const int MAX_N = 100100;
const int MAX_NM = 200200;

int dSet[MAX_NM], newId;
int Map[MAX_N];
int Size[MAX_NM];
ull cnt[MAX_NM];

int n, m;
int op, p, q;

void Init(int x){
    for(int i = 1; i <= x; i++){
        dSet[i] = i;
        cnt[i] = i;
        Map[i] = i;
        Size[i] = 1;
    }
    return;
}

int Find(int x){
    return dSet[x] == x ? x : dSet[x] = Find(dSet[x]);
}

void Union(int a, int b){
    cnt[Find(b)] += cnt[Find(a)];
    Size[Find(b)] += Size[Find(a)];
    dSet[Find(a)] = dSet[Find(b)];
}

bool Same(int a, int b){
    return Find(a) == Find(b);
}

void newNode(int x){
    int FMX = Find(Map[x]);
    //update origin node data
    cnt[FMX] -= x; 
    Size[FMX]--;

    //new Node and initialize it
    dSet[Map[x]] = Map[x] = newId++;
    cnt[Map[x]] = x;
    Size[Map[x]] = 1;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n >> m)
    {
        Init(n);
        newId = n + 1;
        while(m--){
            cin >> op;
            if(op == 1){
                cin >> p >> q;
                if(Same(Map[p], Map[q])){
                    continue;
                }
                Union(Map[p], Map[q]);
            }else if(op == 2){
                cin >> p >> q;
                if(Same(Map[p], Map[q])){
                    continue;
                }
                newNode(p);
                Union(Map[p], Map[q]);
            }else{
                cin >> p;
                cout << Size[Find(Map[p])] << ' ' << cnt[Find(Map[p])] << '\n';
            }
        }
    }
    return 0;
}