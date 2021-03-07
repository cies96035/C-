#include<iostream>
#include<map>
using namespace std;

map<int, int> l;
map<int, int> r;
int x, y;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 3; i++){
        cin >> x >> y;
        l[x]++;
        r[y]++;
    }
    for(auto i : l){
        if(i.second & 1){
            cout << i.first << ' ';
        }
    }
    for(auto i : r){
        if(i.second & 1){
            cout << i.first << '\n';
        }
    }
    return 0;
}