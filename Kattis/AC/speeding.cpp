#include<iostream>
using namespace std;

int n;
int lt, t;
int ld, d;
int Max;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    cin >> lt >> ld;
    for(int i = 1; i < n; i++){
        cin >> t >> d;
        if(Max < (d - ld) / (t - lt)){
            Max = (d - ld) / (t - lt);
        }
        lt = t;
        ld = d;
    }
    cout << Max << '\n';
    return 0;
}