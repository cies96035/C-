#include<iostream>
using namespace std;

int main() {
    char a;
    cin>>a;
    //A的上一個字元剛好是@，不用特地用if判 
    cout<<(char)(a-1)<<endl;
    return 0;
}
