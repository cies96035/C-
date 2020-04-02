#include<iostream>
#include<cstdlib>//rand用到 
#include<ctime>//clock用到 
using namespace std;

int main() {
	//基本上也很少有其他機會用到rand了 
    int a;
    srand(clock());
    a=rand()%2;
    cout<<a<<endl;
    return 0;
}
