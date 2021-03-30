#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 200200;

int N, Q;
ll Value[7];
ll gemAmount[7][MAX_N];
char gem[MAX_N];
int op, K, P;
ll s;

int lowbits(int x){
    return x & (-x);
}
void modify(int type, int pos, int x){
    while(pos <= N){
        gemAmount[type][pos] += x;
        pos += lowbits(pos);
    }
}
int query(int type, int pos){
    int sum = 0;
    while(pos){
        sum += gemAmount[type][pos];
        pos -= lowbits(pos);
    }
    return sum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> Q;
    for(int i = 1; i <= 6; i++){
        cin >> Value[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> gem[i];
        gem[i] -= '0';
        modify(gem[i], i, 1);
    }
    while(Q--){
        cin >> op >> K >> P;
        if(op == 1){
            modify(gem[K], K, -1);
            modify(P, K, 1);
            gem[K] = P;
        }else if(op == 2){
            Value[K] = P;
        }else{
            s = 0;
            for(int i = 1; i <= 6; i++){
                s += Value[i] * ( query(i, P) - query(i, K - 1) );
            }
            cout << s << '\n';
        }
    }
    return 0;
}