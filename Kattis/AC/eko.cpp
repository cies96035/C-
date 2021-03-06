#include<iostream>
using namespace std;
using ll = long long;

const int MAX_N = 1000100;

ll N, M;
ll wood[MAX_N];
ll upper, lower;
ll m;

inline ll Search(){
    ll sum = 0;
    for(int i = 0; i < N; i++){
        if(m < wood[i]){
            sum += wood[i] - m;
        }
    }
    return sum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> wood[i];
        if(wood[i] > upper){
            upper = wood[i];
        }
    }
    upper++;
    while(lower < upper){
        m = (lower + upper) / 2;
        if(Search() < M){
            upper = m;
        }else{
            lower = m + 1;
        }
    }
    cout << lower - 1 << '\n';

    return 0;
}