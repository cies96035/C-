#include<iostream>
#include<stack>
using namespace std;

string str;
bool Test(bool p, bool q, bool r, bool s, bool t){

    bool w, x;
    stack<bool> num;
    for(int i = str.size() - 1; i >= 0; i--){
        if(str[i] == 'A'){
            w = num.top(); num.pop();
            x = num.top(); num.pop();
            num.push(w || x);
        }else if(str[i] == 'C'){
            w = num.top(); num.pop();
            x = num.top(); num.pop();
            num.push(!w || x);
        }else if(str[i] == 'E'){
            w = num.top(); num.pop();
            x = num.top(); num.pop();
            num.push(w == x);
        }else if(str[i] == 'K'){
            w = num.top(); num.pop();
            x = num.top(); num.pop();
            num.push(w && x);
        }else if(str[i] == 'N'){
            w = num.top(); num.pop();
            num.push(!w);
        }else if(str[i] == 'p'){
            num.push(p);
        }else if(str[i] == 'q'){
            num.push(q);
        }else if(str[i] == 'r'){
            num.push(r);
        }else if(str[i] == 's'){
            num.push(s);
        }else if(str[i] == 't'){
            num.push(t);
        }
    }

    return num.top();
}

bool Force(){
    bool WFF = Test(0, 0, 0, 0, 0);
    for(int i = 1; i < 32; i++){
        if(Test(i >> 4, i >> 3 & 1, i >> 2 & 1, i >> 1 & 1, i & 1) != WFF){
            return false;
        }
    }
    return WFF;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> str && str != "0"){
        if(Force()){
            cout << "tautology\n";
        }else{
            cout << "not\n";
        }
    }
    return 0;
}