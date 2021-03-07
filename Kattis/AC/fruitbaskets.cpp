#include<iostream>
using namespace std;
using ll = long long;

const int MAX_WEIGHT = 40400;

ll basket[MAX_WEIGHT];
int N;
int fruit, tmp;
ll sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    basket[0] = 1;
    for(int i = 0; i < N; i++){
        cin >> fruit;
        for(int j = MAX_WEIGHT - 1; j >= 0; j--){
            tmp = j - fruit;
            if(tmp < 0){
                break;
            }
            if(basket[tmp] || tmp == 0){
                basket[j] += basket[tmp];
                if(j >= 200){
                    sum += j * basket[tmp];
                }
            }
        }
    }
    cout << sum << '\n';
    return 0;
}