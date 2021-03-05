#include<iostream>
using namespace std;

int N;
string str;
string tmpStr;
string Min;
int tmpInt;
int minDis;

int SToI(string str){
    int num = 0;
    for(auto s : str){
        num = num * 10 + s - '0';
    }
    return num;
}
string Func(int n){
    string tmp;
    for(int i = n; i; i /= 10){
        tmp = char('0' + i % 10) + tmp;
    }
    for(int i = n; i; i /= 10){
        tmp += ('0' + i % 10);
    }
    return tmp;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N--){
        minDis = 2e9;
        cin >> str;
        tmpStr = str;
        tmpStr.resize(3);
        tmpInt = SToI(tmpStr);
        for(int i = tmpInt - 1, tmp; i <= tmpInt + 1; i++){
            tmp = SToI(Func(i));
            if(std::abs(tmp - SToI(str)) < minDis){
                minDis = std::abs(tmp - SToI(str));
                Min = Func(i);
            }
        }
        cout << Min << '\n';
    }
    return 0;
}