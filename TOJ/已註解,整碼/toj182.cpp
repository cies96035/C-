#include<iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        /*下面b*b+c*c最大為(46340^2)*2
        超過int範圍，不能用int*/ 
        long long a,b,c;
        //輸入a,b,c 
        cin>>a>>b>>c;
        //讓a為最大值 
        if(a<b)swap(a,b);
        if(a<c)swap(a,c);
        //三邊常相等 
        if(a==b&&a==c)cout<<"Equilateral_triangle"<<endl;
        //畢氏定理判斷三角形類型 
        else if(a*a==b*b+c*c)cout<<"Right_triangle"<<endl;
        else if(a*a>b*b+c*c)cout<<"Obtuse_triangle"<<endl;
        else if(a*a<b*b+c*c)cout<<"Acute_triangle"<<endl;
    }
    return 0;
}
