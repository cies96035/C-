#include<iostream>
using namespace std;

int n;
int h, w;
int len;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> h >> w;
    while(n--){
        cin >> len;
        if(h * h + w * w >= len * len){
            cout << "DA\n";
        }else{
            cout << "NE\n";
        }
    }
    return 0;
}