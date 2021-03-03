#include<iostream>
using namespace std;

int n;
char c, lc;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    lc = -1;
    while(n--){
        cin >> c;
        if(c == lc){
            cnt++;
        }
        lc = c;
    }
    cout << cnt << '\n';
    return 0;
}