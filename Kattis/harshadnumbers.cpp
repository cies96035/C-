#include<iostream>
using namespace std;

int n;
bool harsh(int x){
    int sum = 0;
    for(int i = x; i; i /= 10){
        sum += i % 10;
    }
    return !(x % sum);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    while(!(harsh(n))){
        n++;
    }
    cout << n << '\n';
    return 0;
}