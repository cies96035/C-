#include<iostream>
using namespace std;
int main()
{
    int a,b;    
    //�p�G�D�ص�30~40�A���W�Lint�d��A�n��long long
    //���k����줸����1 
    long long ans=1;
    cin>>a>>b;
    if(a>b)swap(a,b);//�קK�X�� 
    //�qa����b 
    while(a<=b)
    {
        ans*=a;
        a++;
    }
    //��X���� 
    cout<<ans<<endl;
    return 0;
}
