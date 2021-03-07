#include<iostream>
using namespace std;
const int MAX_H = 500500;
int N, H;
int Cave[MAX_H];
int n, minFire, mincnt, tmp;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> H;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        if(i & 1){
            Cave[tmp]--;
        }else{
            Cave[H - tmp]++;
        }
    }

    minFire = Cave[0] += (N >> 1);

    for(int i = 0; i < H; i++){
        n += Cave[i];
        if(n < minFire){
            minFire = n;
            mincnt = 1;
        }else if(n == minFire){
            mincnt++;
        }
    }
    cout << minFire << ' ' << mincnt << '\n';
    return 0;
}