#include<iostream>
using namespace std;
using ll = long long;

const int MAX_N = 500500;
ll cnt;
int N;
int arr[MAX_N];

void MergeSort(int *arr, int len){
    if(len == 1){
        return;
    }
    
    int ls = len / 2;
    int rs = len - ls;
    int *lPart = arr;
    int *rPart = arr + ls;

    int lID = 0, rID = 0;

    MergeSort(lPart, ls);
    MergeSort(rPart, rs);
    
    int tmparr[len];
    int tmparrID = 0;

    while(tmparrID < len){
        if(lID < ls && rID < rs){
            if(lPart[lID] <= rPart[rID]){
                cnt += rID;
                tmparr[tmparrID++] = lPart[lID++];
            }else{
                tmparr[tmparrID++] = rPart[rID++];
            }
        }else if(lID < ls){
            cnt += rID;
            tmparr[tmparrID++] = lPart[lID++];
        }else{
            tmparr[tmparrID++] = rPart[rID++];
        }
    }

    for(int i = 0; i < len; i++){
        arr[i] = tmparr[i];
    }

    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    MergeSort(arr, N);

    cout << cnt << '\n';
    return 0;
}