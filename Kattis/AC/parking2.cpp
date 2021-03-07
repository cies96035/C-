#include<iostream>
#include<climits>
using namespace std;

int t, n, Max, Min;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        Max = INT_MIN;
        Min = INT_MAX;
        cin >> n;
        for(int i = 0, tmp; i < n; i++){
            cin >> tmp;
            if(Max < tmp){
                Max = tmp;
            }
            if(Min > tmp){
                Min = tmp;
            }
        }
        cout << (Max - Min) * 2 << '\n';
    }
    return 0;
}