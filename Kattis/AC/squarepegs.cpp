#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_HOUSE = 250;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int house[MAX_HOUSE];
    int plot[MAX_HOUSE / 2];
    int N, M, K, tmp;
    cin >> N >> M >> K;
    K += M;
    for(int i = 0; i < N; i++){
        cin >> plot[i];
        plot[i] *= 4 * plot[i];
    }
    for(int i = 0; i < M; i++){
        cin >> tmp;
        house[i] = 4 * tmp * tmp;
    }
    for(int i = M; i < K; i++){
        cin >> tmp;
        house[i] = 2 * tmp * tmp;
    }
    sort(plot, plot + N);
    sort(house, house + K);

    int cnt = 0;
    for(int i = 0, j = 0; i < K && j < N; i++, j++){
        for(;j < N; j++){
            if(plot[j] > house[i]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}