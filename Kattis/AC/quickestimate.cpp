#include<iostream>
using namespace std;

int N;
string num;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N--){
        cin >> num;
        cout << num.size() << '\n';
    }
    return 0;
}