#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    string out,in;
    char lastout='2',lastin='2';
    cin>>out>>in;
	bool m=0;
    for(int i=0;i<N;i++)
    {
    	//�~�h�M���h���@�ӭn��1
		//�B���঳�~�h���h��������p 
        if((out[i]=='1'||in[i]=='1')&&(out[i]!=lastin||in[i]!=lastout||in[i]==out[i]))
        {
            lastout=out[i];
			lastin=in[i];
		}
        else
        {
        	m=1;
        	break;
		}
    }
    if(!m)cout<<"FENDED OFF!"<<endl;
    else cout<<"FENESTRATION FORTIFICATION FAILURE!"<<endl;
    return 0;
}
