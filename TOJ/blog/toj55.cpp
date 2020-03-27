#include<iostream>
#include<algorithm> 
using namespace std;

int main()
{
    //���D�h�ӿ�J�A�ݭn�[�t 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,M,ask;
    
    //��J���N 
    cin>>N;
    //��JN�Ӻq���s�� 
    int A[N];
    for(int h=0;h<N;h++)cin>>A[h];
    
    //�Ӷ��ǱƦn�A�~��ϥΤ��᪺�G���j�M 
    sort(A,A+N);
    
    //��J���M 
    cin>>M;
    //����M�� 
    while(M--)
    {
        //��J�Q�߰ݪ��q���s�� 
        cin>>ask;
        
        //ans���n��X�����סA��L�O�G���j�M�n�Ϊ�
        //�C���j��վ㬰��l�� 
        int ans=0,max=N,min=0,mid;
        
        //�G���j�M���{���X 
        while(max>=min)
        {
            mid=(max+min)/2;
            if(A[mid]<ask)
                min=mid+1;
            else if(A[mid]>ask)
                max=mid-1;
            else
            {
                /*
                �i�Jelse�o�����Fask����m�bmid 
                min~max�@�w���ƭ�ask���� 
                */
                //�ŦXask���ȥ[�J���� 
                for(int H=min;H<=max;H++)
                {
                    if(ask==A[H])ans++;
                }
                //���}�j�� 
                break;
            }
        }
        //��X���� 
        cout<<ans<<"\n";
    }
    return 0;
}
