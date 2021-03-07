#include<iostream>
using namespace std;

int N;
int K;
int tmp;
int sum;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N--){
        cin >> K;
        sum = 1 - K;
        while(K--){
            cin >> tmp;
            sum += tmp;
        }
        cout << sum << '\n';
    }
    return 0;
}