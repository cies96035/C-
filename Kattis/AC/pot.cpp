#include<iostream>
using namespace std;

int n;
int sum;
int p;

int pow(int base, int p){
    int tmp = 1;
    for(int i = 0; i < p; i++){
        tmp *= base;
    }
    return tmp;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(n--){
        cin >> p;
        sum += pow(p / 10, p % 10);
    }
    cout << sum << '\n';
    return 0;
}