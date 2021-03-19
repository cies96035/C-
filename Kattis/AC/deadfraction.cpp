#include<iostream>
#include<climits>
using namespace std;
using ull = unsigned long long;

string str;
ull noncycle, number;
ull num, den;
ull n, d, x;

ull StringToNum(string num){
    ull sum = 0;
    for(auto c : num){
        sum = sum * 10 + c - '0';
    }
    return sum;
}

ull gcd(ull a, ull b){
    while((a %= b) && (b %= a));
    return a + b;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> str && str != "0"){
        //Init
        str = str.substr(2, str.size() - 5);
        d = 0;
        x = 9;
        den = INT_MAX;

        for(int i = 0; i < str.size(); i++){
            d = d * 10 + 9;
        }//d := 9999999999

        number = StringToNum(str);
        for(int i = 0; i < str.size(); i++){
            noncycle = StringToNum(str.substr(0, i));
            n = number - noncycle;
            
            if(d / gcd(n, d) < den){//update ans
                den = d / gcd(n, d);
                num = n / gcd(n, d);
            }

            d -= x;
            x *= 10;
        }
        cout << num << '/' << den << '\n';
    }
    return 0;
}