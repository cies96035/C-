#include<iostream>
using namespace std;

#define MAXS 1100
int arr[MAXS];
int UP[MAXS];
int DOWN[MAXS];
int n, m, s, peak, valley, tmp;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> s >> n >> m;
    for(int i = 0; i < s; i++)
        cin >> arr[i];
    
    UP[0] = 1;
    for(int i = 1; i < s; i++)
    {
        if(arr[i] > arr[i-1])
            UP[i] = UP[i-1] + 1;
        else
            UP[i] = 1;
    }

    tmp = 1;
    for(int i = s - 2; i >= 0; i--)
    {
        if(arr[i] > arr[i+1])
            tmp++;
        else
            tmp = 1;
        if(tmp >= n && UP[i] >= n)
            peak++;
    }

    DOWN[0] = 1;
    for(int i = 1; i < s; i++)
    {
        if(arr[i] < arr[i-1])
            DOWN[i] = DOWN[i-1] + 1;
        else
            DOWN[i] = 1;
    }

    tmp = 1;
    for(int i = s - 2; i >= 0; i--)
    {
        if(arr[i] < arr[i+1])
            tmp++;
        else
            tmp = 1;
        if(tmp >= m && DOWN[i] >= m)
            valley++;
    }

    cout << peak << ' ' << valley << '\n';
    return 0;
}