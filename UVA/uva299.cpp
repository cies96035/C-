#include<iostream>
using namespace std;

/*
count inversion
�ϥ� merge sort >> D&C
�Ѧҳo��: 
https://www.youtube.com/watch?v=MxiQa22KrSQ
��@�Y�i 
*/ 

int num[2000000];
long long count=0;


//�p���Ӥw�ƦC�ǦC���洫�ƶq�B�ñƧǨ�ӧǦC 
//left~mid���ǦC,mid+1~right�k�ǦC 
void count_inversion(int left,int mid,int right)
{
    int record[right-left+1],//�������T���ǥ�
    leftsub=left,rightsub=mid,//��ӧǦC���_�Y 
    index=0;//�O���Ϊ���m
    
    /*
    �ѩ�w�ƧǡA�̤p�ȥ��w�b��ǦC���̥����@
    �@�@�����ӧǦC���_�Y�A�é�J�������}�C�A�Y�i�ƥX�Ѥp��j���Ǫ��}�C
    �䤤���䪺�ǦC����j�ɡA�p��洫���� 
    */ 
    //����䤤�@�ӧǦC�S�F��i�H��
    while(true)
    {
        if(num[leftsub]<=num[rightsub])
            record[index++]=num[leftsub++];
        else//�p��洫���� 
        {
            record[index++]=num[rightsub++];
            count+=mid-leftsub;//�v��3:25������@ 
        }
        //�פ����:���즳���k�ǦC���@�ӧǦC�������F�A�S�o����ɲפ�
        //�ç��������B�ƻs�ǦC(���ӬO�@�Ӱ϶���q�Ƨ����Ǫ��A�ܦ������Ƨ����Ǫ�) 
        if(leftsub==mid)//���ǦC��������
        {
            //�ƻs���}�C 
            while(rightsub<=right)
                record[index++]=num[rightsub++];
            //����
            break; 
        }
        else if(rightsub>right)//�k�ǦC��������
        {
            while(leftsub<mid)
                    record[index++]=num[leftsub++];
            //����
            break; 
        } 
    }
    for(int i=left,j=0;i<=right;i++,j++)//�ƻs�}�C 
        num[i]=record[j];
    return;
}

//���j 
void mergesort(int left,int right)
{
    if(left!=right)
    {
        //�G��
        int mid=(left+right)/2;
        
        //������b���U�B�z 
        mergesort(left,mid);
        mergesort(mid+1,right);
        
        //�p��洫����
        count_inversion(left,mid+1,right);
    }
    return;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++)
	        cin>>num[i];
	    if(n>0)
	    	mergesort(0,n-1);
	    cout<<"Optimal train swapping takes "<<count<<" swaps.\n";
	    count=0;
	}
    return 0;
}
