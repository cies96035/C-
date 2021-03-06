#include<iostream>
using namespace std;

string sign;
string tmp;
int n;
int k, w;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> k >> w;
        cin >> sign;
        for(int i = 1; i < w; i++){
            cin >> tmp;
            for(int j = k; j >= 0; j--){
                if(sign.substr(sign.size() - j, j) == tmp.substr(0, j)){
                    sign += tmp.substr(j, tmp.size() - j);
                    break;
                }
            }
        }
        cout << sign.size() << '\n';
    }
    return 0;
}