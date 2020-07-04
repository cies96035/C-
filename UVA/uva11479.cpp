#include<iostream>
#include<algorithm>
using namespace std;

int T;
int length[3],Case=1;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>length[0]>>length[1]>>length[2];
        sort(length,length+3);
        cout<<"Case "<<Case++<<": ";
        if(length[2]>length[0]+length[1])
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
