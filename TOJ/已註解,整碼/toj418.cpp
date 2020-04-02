#include<iostream>
using namespace std;

int main()
{
    //幹，我當初這水題拿不到滿分我真是智障 
    long long N,M,P,sum;
    cin>>N>>M>>P;
    cout<<(((N-M)%P*(N%P))%P*(M%P))%P<<endl;
    return 0;
}
