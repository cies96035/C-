#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 101000;

int n, k, tmp;
int t[MAX_N];
int sum;
int Max;
int Mt;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        t[tmp]++;
        t[tmp + 1000]--;
        if(Mt < tmp){
            Mt = tmp;
        }
    }

    for(int i = 0; i <= Mt; i++){
        sum += t[i];
        if(sum > Max){
            Max = sum;
        }
    }
    cout << (Max % k == 0 ? Max / k : Max / k + 1)  << '\n';
}
