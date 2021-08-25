#include<iostream>
#include<string.h>
using namespace std;

bool same(string a, string b){
    int i = 0, j = 0;
    while(i < a.size() && a[i] == '0'){
        i++;
    }
    while(i < b.size() && b[j] == '0'){
        j++;
    }
    return a.substr(i, a.size() - i) == b.substr(j, b.size() - j);
}
int main() {
    string A, B;
    string a, b;
    cin >> A >> a >> B >> b;
    if(A == B && same(a, b)){
        cout << "GOOD" << endl;
    }else if(A == B || same(a, b)){
        cout << "=~=" << endl;
    }else{
        cout << "OTZ" << endl;
    }
}
