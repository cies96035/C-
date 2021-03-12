#include<iostream>
#include<algorithm>
using namespace std;

#define Stan true
#define Ollie false

const int MAX_N = 1001000;
bool stone[MAX_N];
int takeSet[11];
int n, m;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n >> m){
        for(int i = 0; i < m; i++){
            cin >> takeSet[i];
        }
        sort(takeSet, takeSet + m);
        for(int i = 1; i <= n; i++){
            stone[i] = Ollie;
            for(int j = 0; j < m; j++){
                if(takeSet[j] > i){
                    break;
                }
                if(stone[ i - takeSet[j] ] == Ollie){
                    stone[i] = Stan;
                    break;
                }
            }
        }
        if(stone[n] == Stan){
            cout << "Stan wins\n";
        }else{
            cout << "Ollie wins\n";
        }
    }
    return 0;
}