#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int N;
int G;
string tmp;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> G;
        map<string, bool> group;
        for(int i = 0; i < G; i++){
            cin >> tmp;
            if(group.find(tmp) != group.end()){
                group[tmp] = true;
            }else{
                group[tmp] = false;
            }
        }
        for(auto g : group){
            if(g.second == 0){
                cout << "Case #" << i << ": " << g.first << '\n';
                break;
            }
        }
    }
    return 0;
}