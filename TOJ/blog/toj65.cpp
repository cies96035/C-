#include<iostream>
#include<cstdlib>//rand�Ψ� 
#include<ctime>//clock�Ψ� 
using namespace std;

int main() {
	//�򥻤W�]�ܤ֦���L���|�Ψ�rand�F 
    int a;
    srand(clock());
    a=rand()%2;
    cout<<a<<endl;
    return 0;
}
