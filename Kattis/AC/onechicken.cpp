#include<iostream>
using namespace std;

int N, M;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    if(N > M){
        cout << "Dr. Chaz needs " << N - M << " more piece" << (N - M == 1 ? "" : "s") << " of chicken!\n";
    }else{
        cout << "Dr. Chaz will have " << M - N << " piece" << (M -N == 1 ? "" : "s") << " of chicken left over!\n";
    }
    return 0;
}