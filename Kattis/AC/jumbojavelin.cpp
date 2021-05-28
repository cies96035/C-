#include<bits/stdc++.h>
using namespace std;

int N, ipt, sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    sum = 1 - N;
    while(N--){
        cin >> ipt;
        sum += ipt;
    }
    cout << sum << '\n';
    return 0;
}