#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
 
const int MAX_R = 1000005;
const int MAX_SR = 1005;

int n, ipt;
int nums[MAX_R];
int primeF[MAX_R]; //primes : 0, 0 or 1 : -1
int numcnt[MAX_R];
ll sum;
int tmp, t2;

int Count(bool sign, int val, int x){
    if(primeF[x] == -1){
        if(!numcnt[val] && val != 1){
            tmp = val;
            while(tmp < MAX_R){
                numcnt[val] += nums[tmp];
                tmp += val;
            }
        }
        return (sign ? 1 : -1) * numcnt[val];
    }
    t2 = primeF[x] ? primeF[x] : x;
    while(x && x % t2 == 0) x /= t2;
    return Count(!sign, t2 * val, x) + Count(sign, val, x);
}
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    primeF[0] = primeF[1] = -1; // prime factor not exist
    for(ll i = 2; i < MAX_SR; i++){
        if(!primeF[i]){
            for(ll j = i * i; j < MAX_R; j += i){
                if(!primeF[j])
                    primeF[j] = i;
            }
        }
    }

    cin >> n;
    rep(i, 0, n){
        cin >> ipt;
        nums[ipt]++;
    }
    
    sum = (n - 1) * nums[1];
    //sum = (n - nums[1]) * nums[1] + nums[1] * (nums[1] - 1); //one and other + one and one
    rep(i, 2, MAX_R){
        if(nums[i]){
            sum += (n - Count(0, 1, i)) * nums[i]; // primeToi and i
        }
    }
    cout << sum / 2 << '\n';
    return 0;
}