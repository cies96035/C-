#include<iostream>
using namespace std;
using ui = unsigned int;
const int MAX_N = 10010;
const int BIG = 100000;

struct Solution{
    int paid;
    int coins;
    bool operator<(Solution x){
        return paid == x.paid ? coins < x.coins : paid < x.paid;
    }
    Solution(int Paid, int Coins){
        paid = Paid;
        coins = Coins;
    }
    Solution(){
    }
}bestSolution;

int T;
int n, price;
int coin;
int DP[MAX_N];
int vis[MAX_N];
int tmp;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cin >> price >> n;

        bestSolution.paid = bestSolution.coins = BIG;
        for(int i = 0; i < price; i++){
            vis[i] = 0;
            DP[i] = BIG;
        }
        DP[0] = 0;

        for(int vid = 1; vid <= n; vid++){
            cin >> coin;
            for(int i = 0; i < price; i++){
                if(vis[i] != vid && DP[i] != BIG){
                    tmp = i + coin;
                    if(tmp >= price){
                        if( Solution(tmp, DP[i] + 1) < bestSolution){
                            bestSolution = Solution(tmp, DP[i] + 1);
                        }
                        break;
                    }
                    if(DP[i] + 1 < DP[tmp]){
                        DP[tmp] = DP[i] + 1;
                        vis[tmp] = vid;
                    }
                }
            }
        }
        cout << bestSolution.paid << ' ' << bestSolution.coins << '\n';
    }
    return 0;
}
