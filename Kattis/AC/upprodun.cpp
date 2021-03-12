#include<iostream>
using namespace std;

int N, M;
string s;
int avg;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for(int i = 0; i < avg; i++){
        s += '*';
    }
    for(; M; N--){
        avg = M / N;
        M -= avg;
        for(int i = 0; i < avg; i++){
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}