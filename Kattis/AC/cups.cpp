#include<iostream>
#include<algorithm>
using namespace std;
using pis = pair<int,string>;

const int MAX_N = 25;

int n;
string a, b;
pis cup[MAX_N];

int StringToNum(string str){
    int num = 0;
    for(auto s : str){
        num = num * 10 + s - '0';
    }
    return num;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if('0' <= a[0] && a[0] <= '9'){
            cup[i] = pis(StringToNum(a), b);
        }else{
            cup[i] = pis(2 * StringToNum(b), a);
        }
    }
    sort(cup, cup + n);
    for(int i = 0; i < n; i++){
        cout << cup[i].second << '\n';
    }
    return 0;
}