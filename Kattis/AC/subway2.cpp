#include<bits/stdc++.h>
using namespace std;
using ld = long double;

const ld Sub = 60.0 / (40 * 1000);
const ld Wal = 60.0 / (10 * 1000);

struct EDGE{
    int u;
    ld c;
};

struct POINT{
    int vid;
    int x, y;
    POINT(int t, int a, int b): vid(t), x(a), y(b){};
    POINT(){}
};

vector<POINT> S[300];
vector<EDGE> e[300];
int x, y, a, b;
int ipta, iptb;
int Id, Vid;
int V[300];

priority_queue<int> SS;
bool vis[300];

ll dis(POINT a, POINT b){
    return (a.x - b.x) * (a.x - b.x) +
    (a.y - b.y) * (a.y - b.y);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> x >> y >> a >> b;
    while(cin >> ipta >> iptb){
        if(ipta == -1 && iptb == -1){
            Id++;
        }else{
            S[Id].push_back( POINT(++Vid, ipta, iptb) );
        }
    }
    for(int i = 0; i < Id; i++){
        for(int j = 1; j < S[i].size(); j++){
            e[S[i][j - 1].vid] = EDGE(S[i][j].vid, dis(S[i][j - 1], S[i][j]) * Sub);
            e[S[i][j].vid] = EDGE(S[i][j].vid, dis(S[i][j - 1], S[i][j]) * Sub);
        }
    }
    return 0;
}