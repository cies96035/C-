#include<iostream>
#include<map>
using namespace std;
using ld = long double;
using pss = pair<string, string>;


int N, M;
string founder;
string child, mom, dad;
string claimants;
map<string, pss> relation;
ld maxBlood;

ld getBlood(string s){
    if(s == founder){
        return 1;
    }else if(relation.find(s) == relation.end()){
        return 0;
    }

    return ( getBlood(relation[s].first) + getBlood(relation[s].second) ) / 2;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    cin >> founder;
    while(N--){
        cin >> child >> mom >> dad;
        relation[child] = pss(mom, dad);
    }
    while(M--){
        cin >> child;
        if(getBlood(child) > maxBlood){
            claimants = child;
            maxBlood = getBlood(child);
        }
    }
    cout << claimants << '\n';
    return 0;
}