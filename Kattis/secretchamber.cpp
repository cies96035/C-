#include<iostream>
using namespace std;
const int ALPHABET_AMOUNT = 26;
bool trans[ALPHABET_AMOUNT][ALPHABET_AMOUNT];

bool Check(string a, string b){
    if(a.size() != b.size()){
        return false;
    }

    for(int i = 0; i < a.size(); i++){
        if(!trans[a[i] - 'a'][b[i] - 'a']){
            return false;
        }
    }
    return true;
}

void Push(int a, int b){
    if(trans[a][b]){
        return;
    }
    trans[a][b] = true;
    for(int i = 0; i < ALPHABET_AMOUNT; i++){
        if(i != a && trans[i][a]){
            Push(i, b);
        }
        if(i != b && trans[b][i]){
            Push(a, i);
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int m, n;
    char a, b;
    string sa, sb;
    cin >> m >> n;

    for(int i = 0; i < ALPHABET_AMOUNT; i++){
        trans[i][i] = true;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        Push(a - 'a', b - 'a');
    }

    for(int i = 0; i < n; i++){
        cin >> sa >> sb;
        if(Check(sa, sb)){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }

    return 0;
}