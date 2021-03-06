#include<iostream>
#include<queue>
using namespace std;
using ll = long long;

priority_queue<ll, vector<ll>, greater<ll> > pq;
ll T;
ll N;
ll tmp;
ll sum;
ll firsttwo(){
    ll n;
    n = pq.top();
    pq.pop();
    n += pq.top();
    pq.pop();
    pq.push(n);
    return n;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        sum = 0;
        cin >> N;
        while(N--){
            cin >> tmp;
            pq.push(tmp);
        }
        while(pq.size() > 1){
            sum += firsttwo();
        }
        cout << sum << '\n';
        pq.pop();
    }
    return 0;
}

/*
3 5 5 7
5 7 8
8 12
20

*/