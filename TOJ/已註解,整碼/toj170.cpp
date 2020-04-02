#include <iostream>
using namespace std;

//輸出N階星星樹(有些特例要移位)
void coutstartree(int N,int shift)
{
    for(int i=0;i<N;i++)//N層星星樹 
    {
    	for(int j=0;j<shift;j++)//某些特例要移位星星樹
			cout<<' ';
    	for(int j=i+1;j<N;j++)//補星星樹空格
			 cout<<' ';
		for(int j=0;j<2*i+1;j++)//輸出星星
			cout<<'*';
		cout<<endl; 
	}
}

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T; 
    cin>>T;
    char c;
	int n; //宣告c,n變數 
    while(T--)//輸入c,n,共T次 
    {
        cin>>c>>n;
        if(c=='A')
        	coutstartree(n,0);//n層星星樹 
        else if(c=='B')
        {
        	coutstartree(n,0);//雙n層星星樹 
        	coutstartree(n,0);
		}
        else if(c=='C')
        	for(int i=1;i<=n;i++)
        		coutstartree(i,n-i);//i層星星樹，第i層移位n-i層 
        else if(c=='D')
        	coutstartree(10*n,0);
        else if(c=='E')
        {
        	coutstartree(n,2);//移位2層
			for(int i=0;i<3+2*n;i++)
				cout<<'#';//補盆栽
			cout<<endl;
		}
        else if(c=='F')
        	coutstartree(2*n,0);
        else if(c=='G')
        	coutstartree(3*n,0);
        else if(c=='H')
        	coutstartree(7*n,0);
        else if(c=='I')
        	coutstartree(4*n-1,0);
        cout<<endl;
    }
    return 0;
}
