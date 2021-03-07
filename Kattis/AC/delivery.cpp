#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
using ll = long long;
const int MAX_N = 1010;

ll N, K, k, x, t, farest;
ll sum;

struct Delivery{
    ll location;
    ll letters;
    bool operator <(const Delivery & x)const{
        return location == x.location ? letters < x.letters : location < x.location;
    }
    Delivery(){
        location = 0;
        letters = 0;
    }
    Delivery(int a, int b){
        location = a;
        letters = b;
    }
}tmp;
priority_queue<Delivery> Left;
priority_queue<Delivery> Right;

void Solve(priority_queue<Delivery> pq){
    while(!pq.empty()){
        k = K;
        farest = 0;
        while(k > 0 && !pq.empty()){
            if(pq.top().location > farest){
                farest = pq.top().location;
            }
            if(pq.top().letters > k){
                tmp = Delivery(pq.top().location, pq.top().letters - k);
                pq.pop();
                pq.push(tmp);
                k = 0;
            }else if(pq.top().letters < k){
                k -= pq.top().letters;
                pq.pop();
            }else{
                k -= pq.top().letters;
                pq.pop();
            }
        }
        sum += farest;
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    
    for(int i = 0; i < N; i++){
        cin >> x >> t;
        if(x < 0){
            Left.push( Delivery(-x, t) );
        }else{
            Right.push( Delivery(x, t) );
        }
    }
    
    Solve(Left);
    Solve(Right);
    cout << 2 * sum << '\n';
    return 0;
}