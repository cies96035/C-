#include<iostream>
using namespace std;
using ll = long long;
const ll M = 1000000007;
const ll m = 10000000;

ll H(ll previousHash, string transaction, ll token) {
  ll v = previousHash;
  for (int i = 0; i < transaction.size(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string A = "difficult";
    string B = "calculus";
    //string A = "charlie-pays-to-eve-9-sg-coins";
    //string B = "icpc-sg-2018-at-nus";
    ll n;
    cin >> n;
    cout << A << ' ';
    cout << M - H(n, A, 0) % m << endl;
    ll hashValueA = H(n, A, M - (H(n, A, 0) % m));
    cout << B << ' ';
    cout << M - H(hashValueA, B, 0) % m << endl;
    return 0;
}