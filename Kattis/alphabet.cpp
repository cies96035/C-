#include<iostream>
using namespace std;
const int ALPHABET_AMOUNT = 26;
const int MAXSIZE = 60;
int DP[MAXSIZE], M;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string s;
    cin >> s;

    for(int i = 0; i < MAXSIZE; i++){
        DP[i] = 1;
    }

    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < i; j++){
            if(s[j] < s[i]){
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }
    
    for(int i = 0; i < MAXSIZE; i++){
        if(DP[i] > M){
            M = DP[i];
        }
    }
    cout << ALPHABET_AMOUNT - M << '\n';
    return 0;
}