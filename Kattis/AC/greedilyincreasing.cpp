#include<iostream>
using namespace std;

const int MAX_N = 1000100;

int N;
int Max;
int ipt;
int arr[MAX_N], arrId;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    cin >> Max;
    arr[arrId] = Max;
    while(--N){
        cin >> ipt;
        if(Max < ipt){
            Max = ipt;
            arr[++arrId] = Max;
        }
    }

    cout << arrId + 1 << '\n';
    for(int i = 0; i < arrId; i++){
        cout << arr[i] << ' ';
    }
    cout << arr[arrId] << '\n';

    return 0;
}