#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAX_N = 100100;

ll N, M;
bool vised[MAX_N];

struct Road{
    ll des, c, d;
    Road(ll x, ll y, ll z){
        des = x;
        c = y;
        d = z;
    }
    Road(){}
};
vector<Road> edge[MAX_N];
struct City{
    ll pos, t;
    bool operator <(const City & a)const{
        return t > a.t;
    }
    City(ll w, ll x){
        pos = w; t = x;
    }
    City(){}
};
priority_queue<City> Djk;

ll Time(ll curtime, ll c, ll d){
    ll Min = 1e18;
    int sd = sqrt(d);

    for(int i = max(0, sd - 3); i < sd + 3; i++){
        if(Min > d / (i + 1) + i && i >= curtime){
            Min = d / (i + 1) + i;
        }
    }
    if(d / (curtime + 1) + curtime < Min){
        Min = d / (curtime + 1) + curtime;
    }
    return Min + c;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    ll a, b, c, d;
    for(ll i = 0; i < M; i++){
        cin >> a >> b >> c >> d;
        edge[a].emplace_back( Road(b, c, d) );
        edge[b].emplace_back( Road(a, c, d) );
    }
    Djk.push( City(1, 0) );
    while(!Djk.empty()){
        City curCity = Djk.top();
        Djk.pop();
        if(vised[curCity.pos]){
            continue;
        }
        vised[curCity.pos] = true;
        if(curCity.pos == N){
            cout << curCity.t << '\n';
            return 0;
        }
        for(auto e : edge[curCity.pos]){
            Djk.push( City( e.des, Time(curCity.t, e.c, e.d) ) );
        }
    }
    cout << "-1\n";
    return 0;
}