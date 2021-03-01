#include<iostream>
using namespace std;

int N;
int W;
int w, l;
int sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> W >> N;
    while(N--){
        cin >> w >> l;
        sum += w * l;
    }
    cout << sum / W << '\n';
    return 0;
}