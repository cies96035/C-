#include<iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        /*�U��b*b+c*c�̤j��(46340^2)*2
        �W�Lint�d��A�����int*/ 
        long long a,b,c;
        //��Ja,b,c 
        cin>>a>>b>>c;
        //��a���̤j�� 
        if(a<b)swap(a,b);
        if(a<c)swap(a,c);
        //�T��`�۵� 
        if(a==b&&a==c)cout<<"Equilateral_triangle"<<endl;
        //����w�z�P�_�T�������� 
        else if(a*a==b*b+c*c)cout<<"Right_triangle"<<endl;
        else if(a*a>b*b+c*c)cout<<"Obtuse_triangle"<<endl;
        else if(a*a<b*b+c*c)cout<<"Acute_triangle"<<endl;
    }
    return 0;
}
