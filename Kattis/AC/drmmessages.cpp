#include<iostream>
using namespace std;

string A, ans, Lstr, Rstr;
int L, R;

void rotate(char &c, int shift){
    c = (c - 'A' + shift) % 26 + 'A';
}

int sumValue(string s){
    int sum = -'A' * s.size();
    for(auto c : s){
        sum += c;
    }
    return sum;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> A;
    
    Lstr = A.substr(0, A.size() / 2);
    Rstr = A.substr(A.size() / 2, A.size() / 2);
    L = sumValue(Lstr);
    R = sumValue(Rstr);

    for(auto &c : Lstr){
        rotate(c, L);
    }
    for(auto &c : Rstr){
        rotate(c, R);
    }

    for(int i = 0; i < Lstr.size(); i++){
        rotate(Lstr[i], Rstr[i] - 'A');
    }

    cout << Lstr << '\n';
    return 0;
}