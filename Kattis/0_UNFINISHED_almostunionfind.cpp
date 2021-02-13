#include<iostream>
using namespace std;

const int MAX_N = 100100;
int Set[2 * MAX_N];
int op;
int N;
int a, b;
void Init(int x){
    x *= 2;
    for(int i = 0; i < x; i++){
        Set[i] = i;
    }
}
int Find(int x){
    return Set[x] == x ? x : Set[x] = Find(Set[x]);
}

void Union(int a, int b){
    Set[Find(a)] = Set[Find(b)];
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    return 0;
}