//03:50:00
//04:50:00
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
using ll = long long;

const ll MAX_RBN = 300500;
int N, H, R, B;
int bi, ri;
ll bananaTime;
ll bananaCnt;

struct ROPE{
    int la;
    int lb;
    int h;
    int len;

    bool operator< (const ROPE b){
        if(h != b.h){
            return h < b.h;
        }else if(la != b.la){
            return la < b.la;
        }else if(lb != b.lb){
            return lb < b.lb;
        }else{
            return len < b.len;
        }
    }
}rope[MAX_RBN];

struct BANANA{
    int l;
    int h;
    int x;
    int y;

    bool operator< (const BANANA b){
        if(h != b.h){
            return h < b.h;
        }else if(l != b.l){
            return l < b.l;
        }else if(x != b.x){
            return x < b.x;
        }else{
            return y < b.y;
        }
    }
}banana[MAX_RBN];

struct MONKEY{
    ll c;
    ll d;
    ll time;
    int lastChangeHeight;
}monkey[MAX_RBN];

bool GetBanana(const BANANA &b, ll time){
    ll cycle = b.x + b.y;
    ll p = (time / cycle) * cycle;
    
    if(p < time && time <= p + b.x){
        return true;
    }
    return false;
}

void UpdateMonkey(int id, int ropeH, int ropeL){
    monkey[id].time += 
    (ropeH - monkey[id].lastChangeHeight) * monkey[id].c
    + monkey[id].d * ropeL;

    monkey[id].lastChangeHeight = ropeH;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> H >> R >> B;
    for(int i = 0; i < R; i++){
        cin >> rope[i].len >> rope[i].la >> rope[i].lb >> rope[i].h;
        if(rope[i].la > rope[i].lb){
            swap(rope[i].la, rope[i].lb);
        }
    }
    sort(rope, rope + R);
    rope[R].h = INT_MAX;

    for(int i = 1; i <= N; i++){
        cin >> monkey[i].c >> monkey[i].d;
        monkey[i].time = monkey[i].lastChangeHeight = 0;
    }

    for(int i = 0; i < B; i++){
        cin >> banana[i].l >> banana[i].h >> banana[i].x >> banana[i].y;
    }
    sort(banana, banana + B);
    banana[B].h = INT_MAX;

    BANANA lowB;
    while(banana[bi].h != INT_MAX || rope[ri].h != INT_MAX){
        if(banana[bi].h < rope[ri].h){
            lowB = banana[bi];
            bananaTime = 
            (lowB.h - monkey[ lowB.l ].lastChangeHeight) * monkey[ lowB.l ].c
            + monkey[ lowB.l ].time;

            if(GetBanana(lowB, bananaTime)){
                bananaCnt++;
            }
            
            bi++;
        }else{
            UpdateMonkey(rope[ri].la, rope[ri].h, rope[ri].len);
            UpdateMonkey(rope[ri].lb, rope[ri].h, rope[ri].len);
            swap(monkey[ rope[ri].la ], monkey[ rope[ri].lb ]);

            ri++;
        }
    }
    cout << bananaCnt << '\n';

    
    return 0;
}