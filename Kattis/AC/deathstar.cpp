#include<iostream>
using namespace std;

bool blank;
int N;
int m;
int s;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i =0 ; i<N;i++){
        s = 0;
        for(int j = 0; j < N;j++){
            cin >> m;
            if(i != j){
                s |= m;
            }
        }
        if(blank){
            cout << ' ';
        }else{
            blank  = true;

        }
        cout << s;
    }
    cout << '\n';
    return 0;
}