#include<iostream>
using namespace std;

int n, tmp;
int sum, cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> tmp;
        if(tmp >= 0){
            cnt++;
            sum += tmp;
        }
    }
    cout << (long double)sum / cnt << '\n';
    return 0;
}