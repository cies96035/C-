#include<bits/stdc++.h>
using namespace std;

string a, b;
void Add(){
    if(a.size() < b.size()){
        swap(a, b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < a.size(); i++){
        if(i < b.size()){
            a[i] += b[i] - '0';
        }
        if(a[i] > '9'){
            a[i] -= 10;
            if(i + 1 < a.size()){
                a[i + 1]++;
            }else{
                a += '1';
            }
        }
    }
    reverse(a.begin(), a.end());
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b;
    Add();
    cout << a << '\n';
    return 0;
}