#include<iostream>
using namespace std;

int N, k;
int sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N--){
        cin >> k;
        if(k < 0){
            sum += k;
        }
    }
    cout << -sum << '\n';
    return 0;
}