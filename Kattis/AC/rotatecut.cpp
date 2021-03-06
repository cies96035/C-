#include<iostream>
using namespace std;

int t;
int N;
string sentence;
int s, len;
int ls, llen;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> N >> sentence;
        ls = s = 0;
        llen = len = sentence.size();
        for(int i = 0; i < N; i++){
            if(i & 1){
                len -= len / 4;
            }else{
                s += len / 4;
                len -= len / 4;
            }
            if(ls == s && llen == len){
                break;
            }
            ls = s;
            llen = len;
        }
        cout << sentence.substr(s, len) << '\n';
    }
    return 0;
}