#include<bits/stdc++.h>
using namespace std;

int fI(int i){
    int t = 0;
    while(++t){
        if(i % t != 0){
            //cout << i << t << endl;
            return t;
        }
    }
}
    int a,b,c,d,e,f;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int sum = 0;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << i << ' ' << fI(i) << endl;
        if(fI(i) == 2)a++;
        if(fI(i) == 3)b++;
        if(fI(i) == 4)c++;
        if(fI(i) == 5)d++;
        if(fI(i) == 7)e++;
        if(fI(i) == 8)f++;
        sum += fI(i);
    }
    cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << endl;
    cout << sum << endl;
    return 0;
}

/*


100
50 33 8 7 0

1000
500 333 67 14 0

5000
2500 1666 333 72 1

10000
5000 3333 667 143 3
*/