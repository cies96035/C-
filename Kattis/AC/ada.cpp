#include<iostream>
using namespace std;
const int MAX_N = 11;

int n;
int arr[MAX_N][MAX_N];
int depth;
int ans;
void RE(int size){
    bool con = false;
    depth++;

    for(int i = 1; i < size; i++){
        arr[depth][i - 1] = arr[depth - 1][i] - arr[depth - 1][i - 1];
        if(arr[depth][i - 1] != arr[depth][0]){
            con = true;
        }
    }

    ans += arr[depth][size - 2];
    if(con){
        RE(size - 1);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[0][i];
    }

    RE(n);
    cout << depth << ' ' << ans + arr[0][n - 1] << '\n';
    return 0;
}