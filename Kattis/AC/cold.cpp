#include<iostream>
using namespace std;

int n;
int t;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    while(n--){
        cin >> t;
        if(t < 0){
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}