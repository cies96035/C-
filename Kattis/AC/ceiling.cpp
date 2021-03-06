#include<iostream>
using namespace std;
using pii = pair<int,int>;

const int MAX_N = 55;
const int MAX_K = 25;
int n, k;
int tree[MAX_N][MAX_K];
int lower;
int set[MAX_N];
bool tmp[MAX_N];
int cnt;

void Init(){
    for(int i = 0; i < MAX_N; i++){
        set[i] = i;
    }
}

int find(int x){
    if(set[x] == x){
        return x;
    }else{
        return set[x] = find(set[x]);
    }
}

void Union(int a, int b){
    set[find(a)] = find(b);
}


bool Same(int *a, int *b, int s){
    if(s <= 1){
        return true;
    }
    int la[MAX_K];
    int ra[MAX_K];
    int lb[MAX_K];
    int rb[MAX_K];
    int las = 0, ras = 0, lbs = 0, rbs = 0;
    for(int i = 1; i < s; i++){
        if(a[i] < a[0]){
            la[las++] = a[i];
        }else{
            ra[ras++] = a[i];
        }
        if(b[i] < b[0]){
            lb[lbs++] = b[i];
        }else{
            rb[rbs++] = b[i];
        }
    }
    if(las != lbs){
        return false;
    }else{
        return Same(la, lb, las) && Same(ra, rb, ras);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    Init();
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> tree[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(Same(tree[i], tree[j], k)){
                Union(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(tmp[find(i)] == 0){
            tmp[find(i)] = 1;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}