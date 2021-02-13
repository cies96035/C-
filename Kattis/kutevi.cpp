#include<iostream>
#include<queue>
using namespace std;

const int MAX_N = 21;
int N, K, tmp;
int angle[MAX_N];
bool degree[360];
priority_queue<int> pq;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    degree[0] = true;
    pq.push(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> angle[2 * i];
        angle[2 * i + 1] = 360 - angle[2 * i];
    }
    N *= 2;
    while(!pq.empty()){
        int tmp = pq.top();
        pq.pop();
        for(int i = 0; i < N; i++){
            if(degree[(tmp + angle[i]) % 360]){
                continue;
            }else{
                degree[(tmp + angle[i]) % 360] = true;
                pq.push( (tmp + angle[i]) % 360 );
            }
        }
    }
    while(K--){
        cin >> tmp;
        if(degree[tmp]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}