#include<iostream>
using namespace std;

string ipt;
int cnt;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> ipt;
    for(int i = 0; i < ipt.size(); i++){
        if(i % 3 == 0){
            cnt += (ipt[i] != 'P');
        }else if(i % 3 == 1){
            cnt += (ipt[i] != 'E');
        }else{
            cnt += (ipt[i] != 'R');
        }
    }
    cout << cnt << '\n';
    return 0;
}