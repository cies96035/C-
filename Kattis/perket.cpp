#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

const ll MAX_N = 15;
const ll MAX_MEAL = 100000000000;

int N;
ll sourness[MAX_N];
ll bitterness[MAX_N];
ll Min = MAX_MEAL;

void Force(ll x, ll sour, ll bitter, bool take){
    if(x >= N){
        if(take){
            if(Min > std::abs(sour - bitter)){
                Min = std::abs(sour - bitter);
            }
        }
        return;
    }
    if(sour > MAX_MEAL){
        return;
    }
    Force(x + 1, sour * sourness[x], bitter + bitterness[x], true);
    Force(x + 1, sour, bitter, take);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> sourness[i] >> bitterness[i];
    }
    Force(0, 1, 0, false);
    cout << Min << '\n';
    return 0;
}