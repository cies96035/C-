#include<iostream>
#include<vector>
using namespace std;
using pii = pair<int, int>;

const int MAX_N = 110;
int N;
vector<pii> temp;
int U, L;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> L >> U;
        temp.emplace_back(pii(L, U));
    }
    int i = 0;
    for(; i < temp.size(); i++){
        for(int j = i + 1; j < temp.size(); j++){
            if(temp[j].first < temp[i].second || temp[i].first < temp[i].second){
                temp.emplace_back(pii(max(temp[i].first, temp[j].first)))
            }
        }
    }
    return 0;
}