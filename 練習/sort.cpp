//sort�m�� 

#include<iostream>
#include<algorithm>
using namespace std;

#define len 10

struct point
{
	int x,y;
};

//�����ƶǤJ�Ȫ��覡�A�����W�O��const &a�o�˳̦n�A�����]�|���M�� 
bool smaller(int const &a,int const &b)
{
	if(a>=b)return 1;//�p�G�e������>�᭱���ȡA�N�O���T��
	return 0;
}

bool Reverse(int const &a,int const &b)
{
	return 1;
}

//sort�n�Ϊ��a��b�󥦦���K�̱���Ƨ�Struct���\�� 
bool comparepoint(point const &a,point const &b)
{
	//������x�y�бƧǡA��x���j�̱ƫe�� 
	if(a.x>b.x)return 1;
	if(a.x<b.x)return 0;
	
	//x�y�г��@�˴N�A���y�y�СA��Y�y�и��j�̱ƫe�� 
	if(a.y>b.y)return 1;
	return 0;
}

int main()
{
	int A;
	while(cin>>A)
	{
		int array[len]={8,7,1,11,2,6,4,7,3,4};
		if(A==1)
		{	//���ۭq���ƧǡA����Ѥp��j
			sort(array,array+len); 
			for(int i=0;i<len;i++)cout<<array[i]<<' ';
			cout<<endl<<endl;
		}
		else if(A==2)
		{	//�S�w�ϰ쪺�Ƨ�(3~8) 
			sort(array+3,array+8); 
			for(int i=0;i<len;i++)cout<<array[i]<<' ';
			cout<<endl<<endl;
		}
		else if(A==3)
		{	//�ۭq�Ѥj�ƨ�p 
			sort(array,array+len,smaller); 
			for(int i=0;i<len;i++)cout<<array[i]<<' ';
			cout<<endl<<endl;
		}
		else if(A==4)
		{	//�����Ӱ}�C 
			sort(array,array+len,Reverse); 
			for(int i=0;i<len;i++)cout<<array[i]<<' ';
			cout<<endl<<endl;
		}
		else
		{	//�ƧǦۭq����Ƶ��c 
			point P[6]={{1,2},{2,4},{1,5},{2,3},{3,5},{4,7}};
			sort(P,P+6,comparepoint);
			for(int i=0;i<6;i++)cout<<P[i].x<<','<<P[i].y<<' ';
			cout<<endl<<endl;
		}
	}
	return 0;
}

