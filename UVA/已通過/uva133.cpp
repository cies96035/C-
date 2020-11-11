#include<iostream>
#include<iomanip>
using namespace std;

#define MaxN 30
int used[MaxN];//check if the person be count
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n,m,k;
    for(int Case=1 ; cin >> n >> m >> k && ( n || m || k ) ; Case++)
    {
        int Left = n;
        int A=n-1 , B=100*n;

        //until every one has be count
        while(Left > 0)
        {
            for(int i=0 ; i < m ;)
                if(used[ ++A%n ] != Case)
                    i++;

            for(int i=0 ; i < k ; )
                if(used[ --B%n ] != Case)
                    i++;
            
            used[ A%n ] = used[ B%n ] = Case;
            Left--;


            if(A%n != B%n)
            {
                cout<<setw(3) << A%n+1;
                Left--;
            }
            cout << setw(3) << B%n+1;
            
            if(Left > 0)
                cout<<',';
            else
                cout<<'\n';
            
        }
    }
    return 0;
}