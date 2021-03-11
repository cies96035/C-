#include<iostream>
#queue<
#include<vector>
using namespace std;

const int MAX_N = 200200;
int N;
int party[MAX_N];
vector<int> edge[MAX_N];
int P;
int K, L;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < 5; i++){
        cin >> P;
        while(P--){
            cin >> K >> L;
            edge[K].emplace_back(L);
            edge[L].emplace_back(K);
        }

    }
    return 0;
}