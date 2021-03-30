#include<bits/stdc++.h>
using namespace std;

const int MAX_C = 1600;

int b, n, e;
int sb, sn, se;
int c[MAX_C];
int C;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> b >> n >> e;
    cin >> sb >> sn >> se;
    C = (b + n + e) / 2;
    for(int i = 0; i < C; i++){
        cin >> c[i];
    }
    sort(c, c + C);
    return 0;
}