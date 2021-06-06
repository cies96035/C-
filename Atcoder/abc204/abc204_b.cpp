#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1010;
int a;
int N;
int sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(a > 10){
            sum += a - 10;
        }
    }
    cout << sum << '\n';
    return 0;
}