#include<iostream>
#include<cstring>
using namespace std;

const int N=65565;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    /*
	num�x�s�C�ӼƦr���X�{���ơA
	�]���}�C����έt�ơA�ҥH�w�qnum[N]��0 
	min�h�O+65565,max�O-65565 
	*/
    int T,t,x,num[2*N+1],min=N*2,max=0;
    memset(num,0,sizeof(num));
    cin>>T;
    while(T--)
    {
        cin>>t;
        while(t--)
        {
            cin>>x;
            num[N+x]++;
            if(x+N>max)max=N+x;
            if(x+N<min)min=N+x;
        }
        cout<<max-min<<'\n';          
        num[max]--;
        num[min]--;
        //��̤j�γ̤p�ȥΧ���A���U�@�ӳ̤j�̤p�� 
        while(!num[max])max--; 
        while(!num[min])min++;
    }
    return 0;
}

