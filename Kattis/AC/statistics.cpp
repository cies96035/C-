#include<iostream>
using namespace std;

int n;
int Min, Max;
int ipt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int Case = 1; cin >> n; Case++){
        Min = 2000000;
        Max = -Min;
        for(int i = 0; i < n; i++){
            cin >> ipt;
            if(Min > ipt){
                Min = ipt;
            }
            if(Max < ipt){
                Max = ipt;
            }
        }
        cout << "Case " << Case << ": " << Min << ' ' << Max << ' ' << Max - Min << '\n';
    }
    return 0;
}