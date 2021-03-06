#include<iostream>
using namespace std;

int n;
string w;
bool sense = 1;
string IntToStr(int x){
    string s;
    while(x){
        s = char((x % 10) + '0') + s;
        x /= 10;
    }
    return s;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> w;
        if(w == "mumble"){
            continue;
        }
        if(w != IntToStr(i)){
            sense = false;
        }
    }
    if(sense){
        cout << "makes sense\n";
    }else{
        cout << "something is fishy\n";
    }
    return 0;
}