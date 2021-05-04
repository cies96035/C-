#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 202000;
int k, n;
int cnt;
int ipta, iptb;
struct CLASS_ROOM{
    int id;
    int t;
    bool sf;
    bool operator <(const CLASS_ROOM &x) const{
        if(t != x.t){
            return t < x.t;
        }else if(sf != x.sf){
            return sf < x.sf;
        }else{
            return id < x.id;
        }
    }
    CLASS_ROOM(int a, int b, bool c):id(a), t(b), sf(c){}
    CLASS_ROOM(){}
};
bool cmp(const CLASS_ROOM &a,const CLASS_ROOM &b){
    if(a.sf != b.sf){
        return a.sf > b.sf;
    }else if(a.t != b.t){
        return a.t > b.t;
    }else{
        return a.id < b.id;
    }
}
set<CLASS_ROOM> activity;
set<CLASS_ROOM, cmp> usage;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> ipta >> iptb;
        activity.insert(CLASS_ROOM(i, ipta, false));
        activity.insert(CLASS_ROOM(i, iptb, true));
    }
    for(auto i : activity){
        if(i.sf){
            if(usage.find)){
                usage--;
            }
        }else{
            if(usage < k){
                usage++;
                used[i.id] = true;
            }else{
                cnt++;
            }
        }
    }
    cout << n - cnt << '\n';
    return 0;
}

/*
1 2 4 4 5 7 8 9
0 0 0 1 0 1 1 1
0 1 2 0 3 2 3 1

*/