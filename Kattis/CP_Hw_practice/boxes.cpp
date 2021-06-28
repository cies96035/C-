#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 200200;

int N, Q;
int levelAnc[MAX_N][20];
int depth[MAX_N];
int childSize[MAX_N];
int M, arr[20], ans;
vector<int> edge[MAX_N];

int findkthAnc(int n, int x){ //find ancestor
    int t = 0;
    while(x){
        if(x & 1){
            n = levelAnc[n][t];
        }
        x >>= 1;
        t++;
    }
    return n;
}

bool IsAnc(int a, int b){//check if a is b's ancestor
    if(depth[a] >= depth[b])
        return a == b;
    return findkthAnc(b, depth[b] - depth[a]) == a;
}

int LCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    a = findkthAnc(a, depth[a] - depth[b]);
    if(a == b)
        return a;
    for(int i = 19; i >= 0; i--){
        if(levelAnc[a][i] != levelAnc[b][i]){
            a = levelAnc[a][i];
            b = levelAnc[b][i];
        }
    }
    return levelAnc[a][0];
}

int DFS(int node){
    if(node){
        for(int i = 0; levelAnc[node][i] != 0 ; i++){
            levelAnc[ node ][i + 1] = levelAnc[ levelAnc[node][i] ][i];
        }
        depth[node] = depth[ levelAnc[node][0] ] + 1;
    }
    int sum = 1;
    for(auto i : edge[node]){
        sum += DFS(i);
    }
    return childSize[node] = sum;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> levelAnc[i][0];
        edge[ levelAnc[i][0] ].push_back(i);
    }

    DFS(0); //get depth, levelanc, childSize

    cin >> Q;
    while(Q--){
        ans = 0;
        cin >> M;
        for(int i = 0; i < M; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < M; i++){
            ans += childSize[ arr[i] ];
            for(int j = 0; j < M; j++){
                if(i != j && IsAnc(arr[j], arr[i])){
                    ans -= childSize[ arr[i] ];
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}