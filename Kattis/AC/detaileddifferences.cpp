#include<iostream>
using namespace std;

int n;
string a, b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << a << '\n' << b << '\n';
        for(int i = 0; i < a.size(); i++){
            if(a[i] == b[i]){
                cout << '.';
            }else{
                cout << '*';
            }
        }
        cout << "\n\n";
    }
    return 0;
}