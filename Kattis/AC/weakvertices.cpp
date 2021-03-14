#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 25;

bool Edge[MAX_N][MAX_N];
int n;
bool blank;
bool Check(int x){
    for(int i = 0 ; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(Edge[i][x] && Edge[j][x]){
                if(Edge[i][j]){
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n && n != -1)
    {
        blank = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> Edge[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            if(Check(i)){
                if(blank){
                    cout << ' ';
                }else{
                    blank = true;
                }
                cout << i;
            }
        }
        cout << '\n';
    }
    return 0;
}