#include<iostream>
using namespace std;

int N;
bool food[366];
int s, t;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N--){
        cin >> s >> t;
        for(int i = s; i <= t; i++){
            food[i] = true;
        }
    }
    for(int i = 0; i <= 365; i++){
        if(food[i]){
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}