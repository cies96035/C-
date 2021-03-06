#include<iostream>
using namespace std;

int N, M;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    if(M < N){
        swap(N, M);
    }
    N++ , M++;
    for(int i = N; i <= M; i++){
        cout << i << '\n';
    }
    return 0;
}