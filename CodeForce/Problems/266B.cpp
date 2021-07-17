#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int e;
int n, t;
string Queue;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> t;
    cin >> Queue;
    while(t--){
        for(int i = 1; i < Queue.size(); i++){
            if(Queue[i - 1] == 'B' && Queue[i] == 'G'){
                swap(Queue[i], Queue[i - 1]);
                i++;
            }
        }
    }
    cout << Queue << '\n';
    return 0;
}