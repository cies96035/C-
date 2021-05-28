/********************** VERY UGLY CODE ***********************/


#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 26;
int N, Q;
int alpha[MAX_N];
bool table[MAX_N][MAX_N]; // table[a][b] means a < b
vector<int> ans;
bool check(int a, int b){ // return a < b
    char ctmp;
    if(!table[a][b] && !table[b][a]){
        cout << "? " << char(a + 'A') << ' ' << char(b + 'A') << endl;
        cin >> ctmp;
        if(ctmp == '<'){
            table[a][b] = true;
        }else{
            table[b][a] = true;
        }
    }
    return table[a][b];
}
void mergesort(int a, int b){
    if(b - a == 1){
        return;
    }
    int m = (a + b - 1) / 2;
    int li = a, ri = m + 1;
    int tmparr[MAX_N];
    mergesort(a, m + 1);
    mergesort(m + 1, b);
    for(int i = a; i < b; i++){
        if(li == m + 1){
            tmparr[i] = alpha[ri++];
        }else if(ri == b){
            tmparr[i] = alpha[li++];
        }else{
            if(check(alpha[li], alpha[ri])){
                tmparr[i] = alpha[li++];
            }else{
                tmparr[i] = alpha[ri++];
            }
        }
    }
    for(int i = a; i < b; i++){
        alpha[i] = tmparr[i];
    }
    return;
}
// 03
// 01 23
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < MAX_N; i++){
        alpha[i] = i;
    }
    cin >> N >> Q;
    if(N > 5){
        mergesort(0, N);
        cout << "! ";
        for(int i = 0; i < N; i++){
            cout << char(alpha[i] + 'A');
        }
        cout << '\n';
    }else{
        int a = check(0, 1) ? 1 : 0;
        int b = check(2, 3) ? 3 : 2;
        int c = 4;
        int d;
        if(check(a, b)){ //dab
            ans.push_back(1 - a);
            ans.push_back(a);
            ans.push_back(b);
        }else{ //eba
            ans.push_back(5 - b);
            ans.push_back(b);
            ans.push_back(a);
        }
        if( check(c, ans[1]) ){
            if( check(c, ans[0]) ){
                ans.insert(ans.begin(), c);
            }else{
                ans.insert(ans.begin() + 1, c);
            }
        }else{
            if( check(c, ans[2]) ){
                ans.insert(ans.begin() + 2, c);
            }else{
                ans.push_back(c);
            }
        }
        d = check(a, b) ? 5 - b : 1 - a;
        if( check(d, ans[1]) ){
            if( check(d, ans[0]) ){
                ans.insert(ans.begin(), d);
            }else{
                ans.insert(ans.begin() + 1, d);
            }
        }else{
            if( check(d, ans[2]) ){
                ans.insert(ans.begin() + 2, d);
            }else{
                ans.insert(ans.begin() + 3, d);
            }
        }
        cout << "! ";
        for(auto i : ans){
            cout << char('A' + i);
        }
        cout << '\n';
    }
    return 0;
}