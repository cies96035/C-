#include<iostream>
using namespace std;
using ull = unsigned long long;

const ull M = 1000000007;
const int MAX_SEQ = 500050;
const ull VERYBIG = 1e18;

string seq;
ull sum;
ull ZeroAmount = 0;

ull prefix[MAX_SEQ];
ull postfix[MAX_SEQ];
ull *two_pow = new ull[MAX_SEQ] + 1; // two_pow[-1] -> avoid RUNTIME_ERROR

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> seq;

    two_pow[-1] = 500000004; // 1/2
    two_pow[0] = 1;
    for(int i = 1; i < MAX_SEQ; i++){
        two_pow[i] = two_pow[i - 1] * 2;
        if(two_pow[i] > M){
            two_pow[i] %= M;
        }
    }

    for(int i = 1; i < seq.size(); i++){
        if(seq[i - 1] == '?'){
            prefix[i] = prefix[i - 1] + 1;
        }else{
            prefix[i] = prefix[i - 1];
        }
    }

    for(int i = seq.size() - 2; i >= 0; i--){
        if(seq[i + 1] == '?'){
            postfix[i] = postfix[i + 1] + 1;
        }else{
            postfix[i] = postfix[i + 1];
        }
    }

    for(int i = seq.size() - 1; i >= 0; i--){
        if(seq[i] == '0'){
            ZeroAmount += 2;
        }else{
            sum += two_pow[ prefix[i] + postfix[i] - 1] * ( postfix[i] + ZeroAmount );
            if(sum > VERYBIG){
                sum %= M;
            }
        }
    }
    cout << sum % M << '\n';
    return 0;
}