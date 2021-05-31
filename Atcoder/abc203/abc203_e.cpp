#include<bits/stdc++.h>
using namespace std;

const int MAX_M = 200200;
int N, M;
set<int> last;
vector<int> blackpos;
struct Black{
    int x, y;
    bool operator <(const Black &a) const{
        return x == a.x ? y < a.y : x < a.x;
    }
}black[MAX_M];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        cin >> black[i].x >> black[i].y;
    }

    sort(black, black + M);
    last.insert(N);
    for(int id = 0; id < M; id++){
        blackpos.clear();
        blackpos.emplace_back(black[id].y);

        while(id < M && black[id].x == black[id + 1].x){
            id++;
            blackpos.emplace_back(black[id].y);
        }
        vector<int> Erase, Insert;
        for(auto i : blackpos){
            if(last.count(i)){
                Erase.emplace_back(i);
            }
            if(last.count(i - 1)){
                Insert.emplace_back(i);
            }
            if(last.count(i + 1)){
                Insert.emplace_back(i);
            }
        }
        for(auto e : Erase){
            last.erase(e);
        }
        for(auto i : Insert){
            last.insert(i);
        }
    }
    cout << last.size() << '\n';
    return 0;
}