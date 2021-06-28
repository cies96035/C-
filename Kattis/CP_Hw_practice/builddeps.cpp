#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> vs;
set<string> used;
void topology(string a, map<string, vector<string> > & m){
    if(m.find(a) == m.end() & !used.count(a)){
        used.insert(a);
        vs.push_back(a);
        return;
    }else if(used.count(a)){
        return;
    }
    for(auto i : m[a]){
        topology(i, m);
    }
    if(!used.count(a)){
        vs.push_back(a);
    }
    used.insert(a);
    return;

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string filename, tmp;
    map<string, vector<string> > files;

    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, filename);
        stringstream ss(filename);
        ss >> filename;
        filename.pop_back();
        while(ss >> tmp){
            files[tmp].push_back(filename);
        }
    }
    cin >> filename;
    topology(filename, files);
    for(auto c = vs.rbegin(); c != vs.rend(); c++){
        cout << *c << '\n';
    }
    return 0;
}