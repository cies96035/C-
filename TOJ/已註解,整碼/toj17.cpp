#include<iostream>
using namespace std;

//��X�Ӧ�A...A�A�ò��� 
void out(int N,int shift)
{
	while(shift--)cout<<' ';
    //�w�]�n��XN*2+1�ӭ� 
    int n=0;
    //�qA��X��A+n(��楪�b��)(�@N�ӭ�) 
    while(n<N)
    {
        cout<<(char)('A'+n);
        n++;
    }
    //�qA+n��X��A(���k�b��)(�@N+1�ӭ�) 
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
        for(int n=0,shift=N-1;n<N;n++,shift--)//�W�b�� (�]�t���� (�@N�� 
        {
            out(n,shift);
        }
        for(int n=N-1,shift=1;n>0;n--,shift++)//�U�b�� (�@N-1�� 
        {
            out(n-1,shift);
        }
    }
    return 0;
}
