#include<iostream>
#include<queue>
#include<climits>
using namespace std;

const int MAX_N = 1010;

int N;
int D[MAX_N][MAX_N];
int S, T;
bool Set[MAX_N];
int dis[MAX_N];

struct COUNTRY{
    int id;
    int w;
    bool operator<(const COUNTRY x)const{
        return w == x.w ? id > x.id : w > x.w;
    }
    COUNTRY(int a, int b){
        id = a;
        w = b;
    }
    COUNTRY(){
        id = INT_MAX;
        w = INT_MAX;
    }
};

priority_queue<COUNTRY> s;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    cin >> S >> T;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> D[i][j];
        }
    }
    s.push( COUNTRY(S, 0) );
    
    while(s.top().id != T){
        COUNTRY tmp = s.top();
        s.pop();
        Set[tmp.id] = true;
        for(int i = 0; i < N; i++){
            if(Set[i] == true){
                continue;
            }
            s.push( COUNTRY(i, tmp.w + D[tmp.id][i]) );
        }
    }
    cout << s.top().w << '\n';
    return 0;
}