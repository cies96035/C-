#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1000100;
int N, K;
char op;
int a, b;
int BITS[MAX_N];
bool bits[MAX_N];
int lowbits(int x){
    return x & (-x);
}
void modify(int pos){
    int flip = !bits[pos] - bits[pos];
    bits[pos] ^= 1;
    while(pos <= N){
        BITS[pos] += flip;
        pos += lowbits(pos);
    }
}
int query(int pos){
    int sum = 0;
    while(pos){
        sum += BITS[pos];
        pos -= lowbits(pos);
    }
    return sum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> op;
        if(op == 'F'){
            cin >> a;
            modify(a);
        }else{
            cin >> a >> b;
            cout << query(b) - query(a - 1) << '\n';
        }
    }
    return 0;
}