#include<iostream>
using namespace std;
using ll = long long;

const int MAX_N = 1000100;

ll n, m, a, c, x, cnt;
int arr[MAX_N];

bool Search(const int &x, const int &pos, int l, int h){
    int m = (l + h) / 2;
    
    if(arr[m] == x){
        return true;
    }

    if(arr[m] > x && m > pos){
        return Search(x, pos, l, m - 1);
    }
    
    if(arr[m] < x && m < pos){
        return Search(x, pos, m + 1, h);
    }
    
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m >> a >> c >> x;
    
    a %= m;
    c %= m;
    x %= m;

    for(ll i = 0; i < n; i++){
        x = a * x + c;
        if(x >= m){
            x %= m;
        }
        arr[i] = x; 
    }

    for(int i = 0; i < n; i++){
        if( Search( arr[i], i, 0, n - 1) ){
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
