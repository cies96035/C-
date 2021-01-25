#include<iostream>
#include<cstring>
using namespace std;

#define MAX 300000
typedef long long ll;
int A[MAX];
int B[MAX];
int Am[MAX];
int Bm[MAX];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    int a, b, k;
    int tmp;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> k;
        memset(Am, 0, sizeof(int) * (a + 1) );
        memset(Bm, 0, sizeof(int) * (b + 1) );
        for(int i = 0; i < k; i++)
        {
            cin >> A[i];
            Am[ A[i] ]++;
        }
        for(int i = 0; i < k; i++)
        {
            cin >> B[i];
            Bm[ B[i] ]++;
        }
        ll cnt = 0;
        for(int i = 0 ; i < k ; i++)
        {
            int aa = A[i];
            int bb = B[i];
            cnt += (k - Bm[bb] - Am[aa] + 1);
        }
        cout << cnt / 2 << '\n';

    }
    return 0;
}