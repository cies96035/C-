#include<iostream>
#include<cmath>
using namespace std;

bool K[4000000];

string sixteen_to_two(char a)
{
    if(a=='0')return "0000";
    if(a=='1')return "0001";
    if(a=='2')return "0010";
    if(a=='3')return "0011";
    if(a=='4')return "0100";
    if(a=='5')return "0101";
    if(a=='6')return "0110";
    if(a=='7')return "0111";
    if(a=='8')return "1000";
    if(a=='9')return "1001";
    if(a=='a')return "1010";
    if(a=='b')return "1011";
    if(a=='c')return "1100";
    if(a=='d')return "1101";
    if(a=='e')return "1110";
    if(a=='f')return "1111";
} 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string sixteen,two;
    cin>>sixteen;
    int ss=sixteen.size(),ts=ss*4,z[3]={10000000,0,0},u=0;
    for(int i=0;i<ss;i++)
        two+=sixteen_to_two(sixteen[i]);
    for(int i=0;i<ts;i++)
    {
        if(two[i]=='0')z[u%3]++;
        else
        {
            if(z[(u+1)%3]>=z[u%3]&&z[u%3]==z[(u+2)%3]&&
            (ts-i-1)%(z[u%3]+1)==0)
            {
                K[z[u%3]+1]=1;
            }
            u++;
            z[u%3]=0;
        }
    }
    for(int i=1;i<4000000;i++)
        if(K[i])cout<<i<<endl;
    return 0;
}
