#include<bits/stdc++.h>
using namespace std;

const int MAX_3N = 330;

int T;
int N;
int p[MAX_3N];
int sum;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        sum = 0;
        cin >> N;
        N *= 3;
        for(int i = 0; i < N ; i++){
            cin >> p[i];
        }
        sort(p, p + N, greater<int>());
        N /= 3;
        for(int i = 1; N-- && i >= 0; i += 2){
            sum += p[i];
        }
        cout << sum << '\n';
    }
    return 0;
}