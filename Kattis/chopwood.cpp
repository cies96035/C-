#include<iostream>
#include<queue>
using namespace std;

const int MAX_N = 200200;
int v[MAX_N];
int degree[MAX_N];
priority_queue<int, vector<int>, greater<int> > leaf;

int n;
int V;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;

    n--;
    V = n + 2;

    for(int i = 0; i <= n; i++){
        cin >> v[i];
        degree[v[i]]++;
    }

    if(v[n] != V){
        cout << "Error\n";
    }else{
        for(int i = 1; i <= V; i++){
            if(degree[i] == 0){
                leaf.push(i);
            }
        }

        for(int i = 0; i < n; i++){
            cout << leaf.top() << '\n';
            leaf.pop();
            if(--degree[v[i]] == 0){
                leaf.push(v[i]);
            }
        }
        cout << leaf.top() << '\n';

    }

    return 0;
}