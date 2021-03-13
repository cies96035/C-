#include<iostream>
using namespace std;

const int MAX_N = 1001000;

int n;
int H[MAX_N];
int MaxAns;
int MaxH;
int minH;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> H[i];
    }
    
    MaxH = minH = H[0];
    for(int i = 1; i < n; i++){
        if(MaxH <= H[i]){
            if(MaxAns < MaxH - minH){
                MaxAns = MaxH - minH;
            }
            minH = MaxH = H[i];
        }else if(H[i] < minH){
            minH = H[i];
        }
    }

    MaxH = minH = H[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(MaxH <= H[i]){
            if(MaxAns < MaxH - minH){
                MaxAns = MaxH - minH;
            }
            minH = MaxH = H[i];
        }else if(H[i] < minH){
            minH = H[i];
        }
    }

    cout << MaxAns << '\n';
    return 0;
}