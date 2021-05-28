#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100100;
int arr[MAX_N];
int pos[MAX_N];
int n;
vector<int> LIS;

void findLIS(){
    LIS.clear();
    LIS.push_back(arr[0]);
    pos[0] = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > LIS.back()){
            LIS.push_back(arr[i]);
            pos[i] = LIS.size() - 1;
        }else{
            pos[i] = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
            LIS[ pos[i] ] = arr[i];
        }
    }
    for(int i = n - 1, idx = LIS.size() - 1; i >= 0; i--){
        if(pos[i] == idx){
            LIS[idx] = i;
            idx--;
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> n && n){
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        findLIS();
        cout << LIS.size() << '\n';
        for(auto l : LIS){
            cout << l << ' ';
        }
        cout << '\n';
    }
    return 0;
}
