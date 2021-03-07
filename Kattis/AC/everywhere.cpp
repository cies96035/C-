#include<iostream>
#include<set>
using namespace std;

int T;
int n;
string str;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        set<string> S;
        cin >> n;
        while(n--){
            cin >> str;
            S.insert(str);
        }
        cout << S.size() << '\n';
    }
    return 0;
}