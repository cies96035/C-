#include<bits/stdc++.h>
using namespace std;

int N;
int a, b;
char c;
string str;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N--){
        cin >> str;
        if(str == "P=NP"){
            cout << "skipped\n";
        }else{
            stringstream ss(str);
            ss >> a >> c >> b;
            cout << a + b << '\n';
        }
    }
    return 0;
}