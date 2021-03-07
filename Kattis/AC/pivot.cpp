#include<iostream>
#include<climits>
using namespace std;

#define MAXN 100100
typedef long long ll;
int arr[MAXN];
bool pivot[MAXN];
int sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll Max = LONG_LONG_MIN;
    ll Min = LONG_LONG_MAX;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        if(arr[i] > Max)
        {
            Max = arr[i];
            pivot[i] = 1;
        }
    for(int i = n - 1; i >= 0; i--)
        if(arr[i] < Min)
        {
            Min = arr[i];
            if(pivot[i])
                sum++;
        }
    cout << sum << '\n';
    
    return 0;
}