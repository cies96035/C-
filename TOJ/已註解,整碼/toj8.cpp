#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
        char a[1024];
        cin.ignore();
        cin.getline(a,1024);
        
        for(int n=0;n<N;n++)
        {
            for(int k=0;k<strlen(a)/N;k++)
                cout <<a[n+k*N];
        }
        cout<<endl;
    }
    return 0;
}

