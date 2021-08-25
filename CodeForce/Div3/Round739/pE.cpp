#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int T;
string t;
string findOrder(){
    set<char> s;
    string order;
    for(int i = t.size() - 1; i >= 0; i--){
        if(!s.count(t[i])){
            s.insert(t[i]);
            order += t[i];
        }
    }
    reverse(order.begin(), order.end());
    return order;
}

string get_s(string order){
    int cnt[128] = {0}, length = 0;
    for(auto c : t){
        cnt[c]++;
    }
    rep(i, 0, order.size()){
        if(cnt[ order[i] ] % (i + 1)){
            return "-1";
        }
        length += cnt[ order[i] ] / (i + 1);
    }
    return t.substr(0, length);
}

string sim(string s, string order){
    if(s == "-1"){
        return "-1";
    }
    list<char> qc;
    for(auto c : s){
        qc.push_back(c);
    }
    string ans;
    for(auto a : order){
        for(auto c = qc.begin(); c != qc.end(); c++){
            ans += *c;
        }
        qc.remove(a);
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> t;
        string order = findOrder();
        string s = get_s(order);
        string sim_t = sim(s, order);
        if(sim_t == "-1" || sim_t != t){
            cout << "-1\n";
        }else{
            cout << s << ' ' << order << '\n';
        }
    }
    return 0;
}