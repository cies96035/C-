#include<iostream>
#include<sstream>
#include<map>
#include<vector>
using namespace std;

map<string ,vector<string>> Link;
map<string ,string> Parent;
map<string ,bool> vis;
vector<string> torn;

bool FindRoute;
int N;
string tmp, tmp2;
string S, E;

void AddLink(string Line){
    stringstream ss;
    ss << Line;
    ss >> tmp;
    while(ss >> tmp2){
        Link[tmp].emplace_back(tmp2);
        Link[tmp2].emplace_back(tmp);
    }
    return;
}

void Travel(string x){
    if(x == E){
        FindRoute = true;
        return;
    }else if(vis.find(x) != vis.end()){
        return;
    }else if (FindRoute){
        return;
    }
    vis[x] = true;
    for(auto s : Link[x]){
        Travel(s);
        Parent[s] = x;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
        getline(cin, tmp);
        AddLink(tmp);
    }
    cin >> S >> E;
    Travel(S);

    if(FindRoute){
        while(E != S){
            torn.emplace_back(E);
            E = Parent[E];
        }
        cout << S;
        for(int i = torn.size() - 1; i >= 0; i--){
            cout << ' ' << torn[i];
        }
        cout << '\n';
    }else{
        cout << "no route found\n";
    }
    return 0;
}