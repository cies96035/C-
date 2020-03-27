#include<iostream>
using namespace std;
int main()
{
    string a;
    char states='A';//初始狀態為A
    cin>>a;
    //最多執行10000次就停機,初始位置為0
    for(int h=0,place=0;h<10000;h++)
    {
        if(states=='A')
        {
            if(a[place]=='1')
            {
                states='D';
                a[place]='0';
                place+=2;
            }
            else
            {
                states='B';
                place+=1;
            }
        }
        else if(states=='B')
        {
            if(a[place]=='1')
            {
                cout<<a<<endl;
                return 0;
            }
            else
            {
                states='D';
                a[place]='1';
                place-=1;
            }
        }
        else if(states=='C')
        {
            if(a[place]=='1')
            {
                states='A';
                a[place]='0';
                place-=2;
            }
            else
            {
                states='E';
                a[place]='1';
                place+=2;
            }
        }
        else if(states=='D')
        {
            if(a[place]=='1')
            {
                states='E';
                place+=1;
            }
            else
            {
                states='C';
                a[place]='1';
                place+=1;
            }
        }
        else if(states=='E')
        {
            if(a[place]=='1')
            {
                states='C';
                place-=1;
            }
            else
            {
                states='A';
                place+=1;
            }
        }
    }
    cout<<a<<endl;//停機時輸出
    return 0;
}
