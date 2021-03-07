#include<iostream>
#include<stack>
using namespace std;

stack<int> ori;
stack<int> aux;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    int sock;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < 2 * n; i++)
    {
        cin >> sock;
        ori.push(sock);
    }
    while(!ori.empty())
    {
        if(aux.empty() || ori.top() != aux.top()){
            aux.push(ori.top());
            ori.pop();
        }else{
            ori.pop();
            aux.pop();
        }
        cnt++;
    }
    if(aux.empty()){
        cout << cnt << '\n';
    }else{
        cout << "impossible\n";
    }
    
    return 0;
}