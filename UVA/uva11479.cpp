#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
int T,Case=1;
ll length[3];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>T;
    while(T--)
    {
        cin>>length[0]>>length[1]>>length[2];
        sort(length,length+3);
        cout<<"Case "<<Case++<<": ";
        if(length[2]>=length[0]+length[1]||length[0]<=0)
            cout<<"Invalid\n";
        else if(length[0]==length[2])
            cout<<"Equilateral\n";
        else if(length[0]==length[1]||length[1]==length[2])
            cout<<"Isosceles\n";
        else
            cout<<"Scalene\n";
    }
    return 0;
}
