#include<iostream>
using namespace std;

int Min = 1000000000;
int MinId;
int n, j;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> j;
        if(j < Min){
            MinId = i;
            Min = j;
        }
    }
    cout << MinId << '\n';
    return 0;
}