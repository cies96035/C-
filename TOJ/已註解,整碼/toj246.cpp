//�`�N�@�Umod��m�A�קK�W�Xlong long�d��
#include<iostream>
using namespace std;
int main()
{
    long long a,m,b,n;
    char d;
    cin>>a>>m>>b;
    while(m--)
    {
        cin>>n>>d;
        a*=n;
        a%=b;
    }
    cout<<a<<endl;
    return 0;
}
