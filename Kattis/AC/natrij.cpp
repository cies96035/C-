#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cout << setfill('0');
    int second[2] = {0};
    bool s = 0;
    char c;
    int tmp = 0;
    while(cin.get(c))
    {
        if('0' <= c && c <= '9'){

            tmp = tmp * 10 + c - '0';
        }else{
            second[s] = second[s] * 60 + tmp;
            if(c == '\n'){
                if(s == 1)
                    break;
                s = 1;
            }
            tmp = 0;
        }
    }
    int diffSecond = second[1] - second[0];
    if(diffSecond <= 0)
        diffSecond += 86400;
        
    cout << setw(2) << diffSecond / 3600 << ':';
    cout << setw(2) << diffSecond / 60 % 60 << ':';
    cout << setw(2) << diffSecond % 60 << '\n';
    
    return 0;
}