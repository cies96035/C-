#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
using ll = long long;
const int MAX_N = 1010;
int inputArr[MAX_N];
int queryArr[MAX_N * MAX_N];
ll A, B;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n, m, s, tmp;
    int *a, *b;
    for(int Case = 1; cin >> n; Case++){
        cout << "Case " << Case << ":\n";
        for(int i = 0; i < n; i++){
            cin >> inputArr[i];
        }

        s = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                    queryArr[s++] = inputArr[i] + inputArr[j];
            }
        }

        sort(queryArr, queryArr + s);
        cin >> m;
        while(m--){
            cin >> tmp;
            a = upper_bound(queryArr, queryArr + s, tmp);
            b = a - 1;
            if(a >= queryArr + s){
                A = INT_MAX;
            }else{
                A = *a;
            }

            if(b < queryArr){
                B = INT_MIN;
            }else{
                B = *b;
            }

            cout << "Closest sum to " << tmp <<" is ";
            if(A - tmp <= tmp - B){
                cout << A;
            }else{
                cout << B;
            }
            cout << ".\n";
        }
    }
    return 0;
}