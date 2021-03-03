#include<iostream>
#include<map>
using namespace std;

int T;
int n;
int num;
int sum;
int cnt;
map<int, int> DP;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> n;
        DP[0] = 1;
        sum = 0;
        cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> num;
            sum += num;
            if(DP.find(sum - 47) != DP.end()){
                cnt += DP[sum - 47];
            }
            DP[sum]++;
        }
        cout << cnt << '\n';
        DP.clear();
    }
    return 0;
}