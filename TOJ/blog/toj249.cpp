#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,num;
    cin>>n>>num;
    n--;
	long long sum=num,ans=num;
	//�w�]ans��sum���Ĥ@�ӼƦӫD0
	//�קK���t�Ʀӵ��׬�0�����p(�D�ئܤ֭n���@��) 
    while(n--)
    {
        cin>>num;
        sum+=num;
        if(sum>ans)ans=sum;
		//�����s���`�M�̤j�� 
        if(sum<0)sum=0;
        //�p�G�s���`�M<0�A�h�e���N�����F
		//�]�� -sum + num < num ������ 
    }
    cout<<ans<<'\n';
    //��X���� 
}
 
