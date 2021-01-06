#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

#define MaxN 52
int pos[MaxN];
int DP[MaxN][MaxN];

int findMin(int l, int r)//l<= <=r
{
    if(l + 2 > r) //less than two part (l,i) + (i,r)
        return 0;
    if(DP[l][r] != 0) //find minimum before
        return DP[l][r];

    //DP
    DP[l][r] = INT_MAX; 
    for(int i = l + 1; i < r; i++)
    {
        int sum = findMin(l, i) + findMin(i, r);
        if(DP[l][r] > sum)
            DP[l][r] = sum;
    }

    return DP[l][r] += pos[r] - pos[l];
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int l, n;
    while(cin >> l && l != 0 && cin >> n)
    {
        //0 .... l
        pos[0] = 0;
        for(int i = 1; i <= n; i++)
            cin >> pos[i];
        pos[n+1] = l;

        cout<<"The minimum cutting is "<<findMin(0, n+1)<<".\n";
        memset(DP, 0, sizeof(int) * MaxN * MaxN);//initialize
    }
    return 0;
}