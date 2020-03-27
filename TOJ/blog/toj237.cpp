#include<iostream>
using namespace std;

int main() {
    int A1,A2,A3,B1,B2,B3,C1,C2,C3,All;
    cin>>A1>>A2>>A3>>B1>>B2>>B3>>C1>>C2>>C3;
    All=A1+A2+A3;
    cout<<"4 "<<((A2+B2+C2)-All)/2<<endl;
}
