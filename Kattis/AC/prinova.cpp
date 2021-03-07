#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using pii = pair<int, int>;

const int MAX_N = 110;

int N;
int boy[MAX_N];
int diff;
int A, B;
int Max = 0, Maxnum;
int tmp, tmp2;
vector<pii> girl;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> boy[i];
    }
    sort(boy, boy + N);

    cin >> A >> B;
    if( !(A % 2) ){
        A++;
    }
    if(!(B % 2)){
        B--;
    }

    if(boy[0] > A){
        girl.emplace_back( pii(A, boy[0] - A) );
    }else if(boy[N - 1] >= A){
        tmp = *lower_bound(boy, boy + N, A) - A;
        tmp2 = A - *(lower_bound(boy, boy + N, A) - 1);
        girl.emplace_back( pii(A, min(tmp, tmp2)) );
    }
    for(int i = 1; i < N; i++){
        diff = (boy[i] - boy[i - 1]) / 2;
        if( diff % 2 ){
            girl.emplace_back( pii(boy[i - 1] + diff, diff) );
        }else{
            girl.emplace_back( pii(boy[i - 1] + diff - 1, diff - 1));
            girl.emplace_back( pii(boy[i - 1] + diff + 1, diff - 1));
        }
    }
    if(boy[N - 1] < B){
        girl.emplace_back( pii(B, B - boy[N - 1]) );
    }else if(boy[0] <= B){
        tmp = *lower_bound(boy, boy + N, B) - B;
        tmp2 = B - *(lower_bound(boy, boy + N, B) - 1);
        girl.emplace_back( pii(B, min(tmp, tmp2)) );
    }

    for(auto g : girl){
        if(A <= g.first && g.first <= B){
            if(g.second > Max){
                Max = g.second;
                Maxnum = g.first;
            }
        }
    }
    cout << Maxnum << '\n';
    return 0;
}