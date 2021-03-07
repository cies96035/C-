#include<iostream>
using namespace std;

const int MAX = 2000;
int vis[MAX];
int weight, n;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    vis[0] = -1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> weight;
        for(int j = 0; j < 1000; j++){
            if(vis[j] != i && vis[j] != 0){
                if(vis[j + weight] == 0){
                    vis[j + weight] = i;
                }
            }
        }
    }
    for(int i = 0; i <= 1000; i++){
        if(vis[1000 + i]){
            cout << 1000 + i << '\n';
            break;
        }
        if(vis[1000 - i]){
            cout << 1000 - i << '\n';
            break;
        }
    }
    return 0;
}