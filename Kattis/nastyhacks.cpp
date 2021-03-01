#include<iostream>
using namespace std;

int n;
int r, e, c;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    while(n--){
        cin >> r >> e >> c;
        if(e - r > c){
            cout << "advertise\n";
        }else if(e - r == c){
            cout << "does not matter\n";
        }else{
            cout << "do not advertise\n";
        }
    }
    return 0;
}