#include<iostream>
using namespace std;
using ll = long long;
 
int extgcd(int a, int b,int &x, int &y){
    int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else  x = 1, y = 0;
    return d;
}//d = gcd(a, b);

int gcd(int a, int b){
    while((a %= b) && (b %= a));
    return a + b;
}

int n;
ll l1, a1, l2, a2, lt, at;
ll A, B, C;
int ans;
int x, y;
int tmp1, tmp2;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;

        tmp1 = l1;
        tmp2 = a1;

        // l1x + l2y = lt
        // a1x + a2y = at
        A = lt * a2 - l2 * at;
        B = l1 * at - lt * a1;
        C = l1 * a2 - l2 * a1;
        
        if(C == 0){
            tmp1 = gcd(l1, l2);
            lt /= tmp1;
            l1 /= tmp1;
            l2 /= tmp1;

            if(extgcd(l1, l2, tmp1, tmp2) == 1){
                ans = 0;
                tmp1 *= lt;
                tmp2 *= lt;
                if(tmp1 > 0 && tmp2 > 0){
                    ans++;
                    x = tmp1;
                    y = tmp2;
                }
                for(int t = 1; t < 10000; t++){
                    if(tmp1 - l2 * t > 0 && tmp2 + l1 * t > 0){
                        ans++;
                        x = tmp1 - l2 * t;
                        y = tmp2 + l1 * t;
                    }
                    if(tmp1 + l2 * t > 0 && tmp2 - l1 * t > 0){
                        ans++;
                        x = tmp1 + l2 * t;
                        y = tmp2 - l1 * t;
                    }
                    if(ans > 1){
                        break;
                    }
                }
                if(ans == 1){
                    cout << x << ' ' << y << '\n';
                }else{
                    cout << "?\n";
                }
            }else{
                cout << "?\n";
            }
        }else if((A % C) || (B % C)){
            cout << "?\n";
        }else if(A / C < 1 || B / C < 1){
            cout << "?\n";
        }else if(A / C + B / C == 0){
            cout << "?\n";
        }else{
            cout << A / C << ' ' << B / C << '\n';
        }
    }
    return 0;
}