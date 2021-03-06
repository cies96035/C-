#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 100100;

int n;
int h[MAX_N];
int Min = 200000000;
int value;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    h[n++] = 0;
    sort(h, h + n);

    for(int i = 0; i < n; i++){
        value = h[i] + n - i - 1;
        if(value < Min){
            Min = value;
        }
    }
    cout << Min << '\n';
    return 0;
}