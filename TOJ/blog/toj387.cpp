#include<iostream>
using namespace std;
int main()
{
    int A,L;
    cin>>A>>L;
    L*=L;//�̪쪺�I���n 
    for(int day=0;true;day++)
    {
        if(L<=A)//��I���n<=A�A��X�ĴX�Ѩõ��� 
        {
            cout<<day<<endl;
            return 0;
        }
        L/=2;//�C�Ѭ屼�@�b 
    }
    return 0;
}
