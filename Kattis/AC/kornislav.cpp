#include<iostream>
#include<algorithm>
using namespace std;

int len[4];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 4; i++){
        cin >> len[i];
    }
    sort(len, len + 4);

    cout << len[0] * len[2] << '\n';
    return 0;
}