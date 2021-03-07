#include<iostream>
using namespace std;

const int MAXQ = 100100;
int pos[MAXQ];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N, Q;
    int A, B, C;

    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> pos[i];
    }

    while(Q--){
        cin >> A >> B >> C;
        if(A == 1){
            pos[B] = C;
        }else if(A == 2){
            cout << std::abs(pos[B] - pos[C]) << '\n';
        }
    }
    return 0;
}