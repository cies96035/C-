#include<iostream>
using namespace std;

int N, P, tmp;
int sum = 0, Max = 0;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> P;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        tmp -= P;
        sum += tmp;
        if(sum > Max){
            Max = sum;
        }else if(sum < 0){
            sum = 0;
        }
    }
    cout << Max << '\n';
    return 0;
}