#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAX_X = 33000;

bool isntPrime[MAX_X];
vector<int> prime;
set<pii> ans;
int n, x;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 2; i < MAX_X; i++){
        if(i * i < MAX_X){
            if(!isntPrime[i]){
                for(int j = i * i; j < MAX_X; j += i){
                    isntPrime[j] = true;
                }
                prime.emplace_back(i);
            }
        }else{
            if(!isntPrime[i]){
                prime.emplace_back(i);
            }
        }
    }
    cin >> n;
    while(n--){
        cin >> x;
        for(auto i : prime){
            if(2 * i > x){
                break;
            }
            if(!isntPrime[x - i]){
                ans.insert(pii(i, x - i));
            }
        }
        cout << x << " has " << ans.size() << " representation(s)\n";
        for(auto ii : ans){
            cout << ii.first << '+' << ii.second << '\n';
        }
        cout << '\n';
        ans.clear();
    }
    return 0;
}