#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_Q = 1e6 + 5;
int cnt[MAX_Q];
int ans = 0;
stack<int> arr;
void pop(){
    cnt[arr.top()]--;
    if(cnt[arr.top()] == 0){
        ans--;
    }
    arr.pop();
}
void push(int x){
    arr.push(x);
    if(cnt[x] == 0){
        ans++;
    }
    cnt[x]++;
}

const int l2 = 21;
struct NODE{
    int val;
    vector<int> ch;
    int anc[l2];
    vector<int> queryIdx;
}nodes[MAX_Q];
int nid = 1;

void setAnc(int idx, int par){
    nodes[idx].anc[0] = par;
    rep(i, 1, l2)
        nodes[idx].anc[i] = nodes[nodes[idx].anc[i - 1]].anc[i - 1];
}

int FindAnc(int idx, int num){
    int i = 20;
    while(num){
        int step = (1 << i);
        if(step <= num){
            idx = nodes[idx].anc[i];
            num -= step;
        }
        i--;
    }
    return idx;
}

int queryAns[MAX_Q], qid;
stack<int> changeLog;


void DFS(int cur){
    if(cur != 0)
        push(nodes[cur].val);
    for(auto q:nodes[cur].queryIdx){
        queryAns[q] = ans;
    }
    for(auto c:nodes[cur].ch){
        DFS(c);
    }
    if(cur != 0)
        pop();
}
void f(){
    int n, x, cur = 0;
    cin >> n;
    char op;
    changeLog.push(0);
    rep(i, 0, n){
        cin >> op;
        if(op == '+'){
            cin >> x;
            nodes[nid].val = x;
            nodes[cur].ch.push_back(nid);
            setAnc(nid, cur);
            cur = nid++;
            changeLog.push(cur);
        }else if(op == '-'){
            cin >> x;
            cur = FindAnc(cur, x);
            changeLog.push(cur);
        }else if(op == '!'){
            changeLog.pop();
            cur = changeLog.top();
        }else if(op == '?'){
            nodes[cur].queryIdx.push_back(qid++);
        }
    }
    DFS(0);
    rep(i, 0, qid){
        cout << queryAns[i] << '\n';
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t--) f();
    
    return 0;
}