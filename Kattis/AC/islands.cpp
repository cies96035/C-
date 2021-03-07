#include<iostream>
using namespace std;

int N;
int arr[12];
int cnt;
int num;
int flg;
int Max, Maxid;

void travel(int x, const int n){
    if(arr[x] <= 0){
        return;
    }else if(arr[x] != n){
        if(arr[x] > Max){
            Max = arr[x];
        }
        return;
    }
    arr[x] = -1;
    travel(x - 1, n);
    travel(x + 1, n);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cnt = 0;
        flg = true;
        cin >> num;
        for(int j = 0; j < 12; j++){
            cin >> arr[j];
        }
        while(flg){
            Max = 0;
            flg = false;
            for(int j = 0; j < 12; j++){
                if(arr[j] > Max){
                    flg = true;
                    Max = arr[j];
                    Maxid = j;
                }
            }
            Max = 0;
            travel(Maxid, arr[Maxid]);
            for(int j = 0; j < 12; j++){
                if(arr[j] == -1){
                    arr[j] = Max;
                }
            }
            if(flg){
                cnt++;
            }
        }
        cout << num << ' ' << cnt << '\n';
    }
    return 0;
}