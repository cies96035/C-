#include<iostream>
using namespace std;

int a, b;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b;
    while(a != b){
        if(a < b){
            cnt += b - a - 1;
            a = b;
        }else if(a & 1){
            a++;
        }else{
            a /= 2;
        }
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}