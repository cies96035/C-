#include<iostream>
using namespace std;

const int MAX_Q = 1100;
int Q, k;
int used[MAX_Q];
int pos[MAX_Q];
int f0, f1;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> Q;
    for(int i = 1; i <= Q; i++){
        cin >> k;
        f0 = f1 = 1;
        for(int j = 2; true; j++){
            f0 += f1;
            if(f0 >= k){
                f0 %= k;
            }
            if(used[f0] == i){
                cout << pos[f0] << '\n';
                break;
            }
            used[f0] = i;
            pos[f0] = j;
            swap(f0, f1);
        }
    }
    return 0;
}