#include<iostream>
#include<cmath>
#include<sstream>
using namespace std;

typedef long double ld;
typedef long long ll;

ld Abs(ld num)
{
    return num < 0 ? -num : num;
}

//check two number is same
bool same(ld a, ld b)
{
    return Abs(a-b) <= 1e-6;
}

//AeB
//make 0 <= A < 1 
//10.0e3 -> 0.1e5
//0.01e2 -> 0.1e1
void normalize(ld *number,ll *Base)
{
    ll n = floor(log10l(*number)) + 1;
    *Base += n;
    *number /= powl(10.0,n);
    return ;
}

ll ten_to_two(ld *number,ll *Power)
{
    //change ten base to two base
    //get Power and float part
    ll B_copy = log2l( *number ) + *Power * log2l(10.0) ;
    *number *= powl(2.0, log2l(10)* *Power - B_copy);
    *Power = log2l ( B_copy==0 ? 1 : B_copy ) + 1;

    while(*number > 1 || same(*number,1.0))
        *number -= 1;

    //find first part
    ld num=0, two_pow=1;

    for(ll M = 0 ; M <= 10 ; M ++)
    {
        if( same( *number , num ) )
            return M;
        two_pow *= 0.5;
        num += two_pow;
        //num => 0.0 0.5 0.75 0.875 ...
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string str;
    ld number;
    ll base;
    while(getline(cin,str)&&str!="0e0")
    {
        //get A,B by "AeB"
        stringstream sstr;
        for(int i=0;i<str.size();i++)
            if(str[i]=='e')
            {
                sstr << str.substr(0, i) << ' ' << str.substr(i+1, str.size() - i + 1 );
                break;
            }
        sstr>>number>>base;
        normalize(&number, &base);
        
        cout<< ten_to_two(&number, &base) <<' '<< base << '\n';
    }
    return 0;
}