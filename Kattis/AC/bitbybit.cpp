#include<iostream>
#include<cstring>
using namespace std;

#define BIT_SIZE 32
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    while(cin >> t && t != 0)
    {
        int arr[BIT_SIZE];
        string op;
        int i, j;
        memset(arr, -1, sizeof(arr));
        while(t--)
        {
            cin >> op;
            if(op == "CLEAR")
            {
                cin >> i;
                arr[i] = 0;
            }
            else if(op == "SET")
            {
                cin >> i;
                arr[i] = 1;
            }
            else if(op == "OR")
            {
                cin >> i >> j;
                if(arr[i] == 1 || arr[j] == 1)
                    arr[i] = 1;
                else if(arr[i] == -1 || arr[j] == -1)
                    arr[i] = -1;
                else
                    arr[i] = 0;
                
            }
            else if(op == "AND")
            {
                cin >> i >> j;
                if(arr[i] == 0 || arr[j] == 0)
                    arr[i] = 0;
                else if(arr[i] == -1 || arr[j] == -1)
                    arr[i] = -1;
                else
                    arr[i] = 1;
                
            }
        }
        for(int i = BIT_SIZE - 1; i >= 0; i--)
            if(arr[i] == -1)
                cout << '?';
            else
                cout << arr[i];
        cout << '\n';
    }
    return 0;
}