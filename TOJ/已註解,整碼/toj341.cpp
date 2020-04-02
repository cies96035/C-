#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{ 
    int k; 
    cin>>k; 
    while(k--) 
    { 
        double a,b,c,d;
        cin>>a>>b>>c>>d;
		//用define可以不用吃記憶體空間又兼顧可讀性
		//不然Rank好後面... 
        #define a2 pow(a,2)
        #define a3 pow(a,3)
        #define b2 pow(b,2)
        #define b3 pow(b,3)
		//把一些重複使用的式子定義，不用重複寫太多次... 
		#define m1 ((b*c)/(6*a2)-(b3/(27*a3))-(d)/(2*a))
		#define m2 ((c)/(3*a)-(b2)/(9*a2))
        cout<<fixed<<setprecision(3)<<
		(-b)/(3*a)+cbrt(m1+sqrt(pow(m1,2)+pow(m2,3)))+cbrt(m1-sqrt(pow(m1,2)+pow(m2,3)))
		<<endl; 
    } 
    return 0;
}
