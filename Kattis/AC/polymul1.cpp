#include<iostream>
using namespace std;
const int MAX_T = 110;
const int MAX_N = 550;

int T;
int a[MAX_N], b[MAX_N], ans[MAX_N];
int aId, bId, ansId;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cin >> aId;
        for(int i = 0; i <= aId; i++){
            cin >> a[i];
        }

        cin >> bId;
        for(int i = 0; i <= bId; i++){
            cin >> b[i];
        }

        ansId = aId + bId;
        for(int i = 0; i <= ansId; i++){
            ans[i] = 0;
        }

        for(int i = 0; i <= aId; i++){
            for(int j = 0; j <= bId; j++){
                ans[i + j] += a[i] * b[j];
            }
        }
        
        cout << ansId << '\n' << ans[0];
        for(int i = 1; i <= ansId; i++){
            cout << ' ' << ans[i];
        }
        cout << '\n';
    }
    return 0;
}