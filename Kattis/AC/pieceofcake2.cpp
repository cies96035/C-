#include<iostream>
using namespace std;

int n, h, v;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> h >> v;
    if(v < n - v){
        v = n - v;
    }
    if(h < n - h){
        h = n - h;
    }
    cout << 4 * h * v << '\n';
    return 0;
}