#include<iostream>
using namespace std;

#define maxA 10000001
pair<int,int> prime[maxA];
//prime[i]�Ai.first����i�̤j����]�ơAi.second����i�ĤG�j����]�� i>=2

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0); 
    
    //�w�]1���̤j��]�ƬO1(��ڤW�ä��O)�A�����F�u���@�ӽ�]�ƪ��බ�Q��ܥX1�A�n�o�˹w�] 
    prime[1].first=1;
    int N,A;
    
    //�z�k�A���]�ƥ�i�h��]�ƪ����Ƹ̡A�u�D�̤j����]��     
    for(int i=2;i<maxA;i++)
    { 
        //�o��̤j��]��
        if(!prime[i].first)
            for(int j=i;j<maxA;j+=i)
                prime[j].first=i;
                
        /*
        �o��ĤG�j��]�� 
        �p�Gi��2*3*5^4�A��2*3*5^3���ĤG�j 
        �p�Gi��2*3*5^3�A��2*3*5^2���ĤG�j...
        �p�Gi��2*3*5�A�ĤG�j��(2*3*5)/5���̤j��]�Ƥ]�N�O3 
        */ 
        N=i/prime[i].first;
        prime[i].second = (prime[N].first==prime[i].first) ? prime[N].second : prime[N].first;
    } 
    
    cin>>N;
    while(N--)
    {
        cin>>A;
        //������X�ӼƦr�e��j����]�ƧY�i 
        cout<<prime[A].second<<' '<<prime[A].first<<'\n';
    }
    return 0;
}
