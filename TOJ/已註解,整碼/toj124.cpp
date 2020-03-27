#include<iostream>
using namespace std;
int main()
{
    int year,mon,day;
    string doodle,reviews;
    cin>>year>>mon>>day>>doodle>>reviews;
    cout<<1997+year<<"/"<<mon<<"/"<<day<<endl;
    cout<<"Doodle Name: "<<doodle<<endl;
    cout<<"Reviews: "<<reviews<<endl;
    return 0;
}
