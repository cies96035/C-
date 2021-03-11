#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 100100;

int depth[MAX_N];
bool isLeave[MAX_N];
int v[MAX_N];
int D[MAX_N], dId;
int n, k;
int ipt;
int Max;
int sum;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;

    isLeave[0] = true;
    for(int i = 0; i < k; i++){
        cin >> v[i];
    }
    for(int i = 1; i < n; i++){
        cin >> ipt;
        if(isLeave[ipt]){
            isLeave[ipt] = false;
        }
        isLeave[i] = true;
        depth[i] = depth[ipt] + 1;
        if(Max < depth[i]){
            Max = depth[i];
        }
    }   
    for(int i = 0; i < n; i++){
        if(isLeave[i]){
            D[dId++] = depth[i];
        }
    }
    Max++;
    sort(v, v + k);
    sort(D, D + dId);
    for(int i = 0; i < dId; i++){
        cout << (Max - D[dId - i - 1]) << ' ' << v[i] << endl;
        sum += (Max - D[dId - i - 1]) * v[i];
    }
    cout << sum << '\n';
    return 0;
}