#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

const int MAX_R = 11;

string rountines[MAX_R];
int changes[MAX_R][MAX_R];
int R;
int GetChange(string a, string b){
    int cnt = 0;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            i++;
        }else if(a[i] > b[j]){
            j++;
        }else{
            i++;
            j++;
            cnt++;
        }
    }
    return cnt;
}

int Solve(){

    int permutation[MAX_R];
    int sum = INT_MAX, cnt;
    for(int i = 0; i < R; i++){
        permutation[i] = i;
    }
    do{
        cnt = 0;
        for(int i = 1; i < R; i++){
            cnt += changes[ permutation[i - 1] ][ permutation[i] ];
        }
        if(cnt < sum){
            sum = cnt;
        }
    }while(next_permutation(permutation, permutation + R));

    return sum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> R;
    for(int i = 0; i < R; i++){
        cin >> rountines[i];
        for(int j = 0; j < i; j++){
            changes[i][j] = changes[j][i] = GetChange(rountines[j], rountines[i]);
        }
    }

    cout << Solve() << '\n';
    return 0;
}