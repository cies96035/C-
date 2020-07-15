/*
Input name

Output Hello ,[name] !
*/

#include<iostream>
using namespace std;
int main()
{
    char name[100];
    cin.getline(name,100);
    cout<<"Hello ,"<<name<<" !"<<endl;
    return 0;
}
