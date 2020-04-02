#include<iostream>
using namespace std;

//輸出該行A...A，並移位 
void out(int N,int shift)
{
	while(shift--)cout<<' ';
    //預設要輸出N*2+1個值 
    int n=0;
    //從A輸出到A+n(單行左半部)(共N個值) 
    while(n<N)
    {
        cout<<(char)('A'+n);
        n++;
    }
    //從A+n輸出到A(單行右半部)(共N+1個值) 
    while(n>=0)
    {
        cout<<(char)('A'+n);
        n--;
    }
    cout<<endl;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int N;
    while(cin>>N)
    {
        for(int n=0,shift=N-1;n<N;n++,shift--)//上半部 (包含中間 (共N行 
        {
            out(n,shift);
        }
        for(int n=N-1,shift=1;n>0;n--,shift++)//下半部 (共N-1行 
        {
            out(n-1,shift);
        }
    }
    return 0;
}
