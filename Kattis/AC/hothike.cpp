#include<iostream>
using namespace std;

const int MAX_N = 60;
int n;
int t[MAX_N];
int mint, mind;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    mint = mind = 10000;
    for(int i = 0; i < n; i++){
        cin >> t[i];
        if(i >= 2){
            if(max(t[i - 2] , t[i]) < mind){
                mint = i - 2; 
                mind = max(t[i - 2] , t[i]);
            }
        }
    }
    cout << mint + 1 << ' ' << mind << '\n';
    return 0;
}