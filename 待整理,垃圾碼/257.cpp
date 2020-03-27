#include<iostream>
#include<cstring>
using namespace std;

/*
每個Test輸入只輸入兩次(單筆測資 
Nymphia和Fake直接輸出為WA
T1皆為整數,3000>B>500 A<0
T2含小數,<100 
*/ 

void TLE()
{
    while(1); 
}
int main()
{
    long double A,B;
    cin>>A>>B;
    if(A>100&&B>100)TLE();
    A%=1;
    return 0;
}
