#include<iostream>
#include<cstring>
#include<queue> 
using namespace std;

#define card_size 34//�@34�صP

//�����P���W�r�A��K��X 
const string card_name[card_size]=
{"1T","2T","3T","4T","5T","6T","7T","8T","9T",
"1S","2S","3S","4S","5S","6S","7S","8S","9S",
"1W","2W","3W","4W","5W","6W","7W","8W","9W",
"DONG","NAN","XI","BEI","ZHONG","FA","BAI"};

//�������bť�ƻ�P�B�H�άO�_�bť�P 
bool ans[card_size],isnt_ready=1;

//�@�Ӭ����C��card�ƶq���`�ƪ�struct 
struct Card
{
	int num[card_size],all_num=13;
}card;

inline void Init()//��l�� (�Ω�C�������A��d���ƶq�k�s�קK�P�_��W����) 
{
	memset(card.num,0,sizeof(card.num));
	memset(ans,0,sizeof(ans));
	card.all_num=13;
	isnt_ready=1;
	return;
}

//��r���ন�d��ID�A�A�O����ID���ƶq (�Ω�@�}�l��J�A�ഫ���i�θ��) 
inline void string_to_card_num(string k)
{
	if(k[0]>='1'&&k[0]<='9')
		card.num[k[0]-'1'+(k[1]=='T'?0:(k[1]=='S'?9:18))]++;
	else
		for(int i=27;i<card_size;i++) 
		if(k==card_name[i])card.num[i]++;
	return ;
} 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int Case=1;//�ĴX������
	string input_card[13];//�P�� 
	while(cin>>input_card[0])
	{
		if(input_card[0]=="0")break;
		
		//�����P�դ��e 
		string_to_card_num(input_card[0]);
		for(int i=1;i<13;i++)
		{
			cin>>input_card[i];
			string_to_card_num(input_card[i]);
		}
		
		//BFS�Φ�C�A��card�M�w�Y�Leye����i�h 
		queue<Card> toBFS;
		toBFS.push(card);
		
		//�D�ػݨD���Ӥ���W�X�@��eye�A�ҥH�n�bBFS�~��eye 
		for(int i=0;i<card_size;i++)
		{
			if(card.num[i]>=2)
			{
				card.num[i]-=2;
				card.all_num-=2;
				toBFS.push(card);
				card.num[i]+=2;
				card.all_num+=2;
			}
		}
		
		//�}�lBFS
		//�o�̦��Ӱ��D�A�S�������w���L���a��A�ҥH�|�j�M���h���A�ɶ������A�ݧﵽ 
		while(!toBFS.empty())
		{
			Card x=toBFS.front();
			toBFS.pop();
			
			//��1�i�A�i�H��eye�@��ť�P 
			if(x.all_num==1) 
				for(int i=0;i<card_size;i++)
					if(x.num[i])
						ans[i]=true;
			
			//��2�i�A�i��i�H��pong��chow�γ����O�@��ť�P 
			if(x.all_num==2)
			{
				for(int i=0;i<card_size;i++)
				{
					if(x.num[i]==2)//���Y�Ӻ�����2�i�ɡA�i�H�F��pong 
					{
						ans[i]=true;
						break;
					}
					//�p�G�i�H�F���S�w3�ӳs��A�i�H�F��chow 
					else if(i<27&&i%9>1&&x.num[i]+x.num[i-1]+x.num[i-2]==2) 
						ans[x.num[i]?x.num[i-1]?i-2:i-1:i]=true;
				} 
			} 
			for(int i=0;i<card_size;i++)
			{
				if(x.num[i]>=3)//pong
				{
					x.num[i]-=3;//��pong����iqueue 
					x.all_num-=3;//�`�Ƥ@�˦��� 
					toBFS.push(x);
					x.num[i]+=3;//�[�^�ӡA�~�򤧫᪺�P�_ 
					x.all_num+=3;
				}
				if(i<27&&i%9>1&&x.num[i]&&x.num[i-1]&&x.num[i-2])//chow
				{
					for(int j=i-2;j<=i;j++)x.num[j]--;
					x.all_num-=3;
					toBFS.push(x);
					for(int j=i-2;j<=i;j++)x.num[j]++;
					x.all_num+=3;
				}
			} 
			//*���ե�*/for(int i=0;i<card_size;i++)cout<<x.num[i]<<' ';cout<<endl;
		}
		
		//��X���� 
		cout<<"Case "<<Case++<<':';
		for(int i=0;i<card_size;i++)
			if(ans[i]&&card.num[i]!=4)
			{
				cout<<' '<<card_name[i];
				isnt_ready=0;
			}
		if(isnt_ready)cout<<" Not ready";
		cout<<'\n';
		
		Init();//��l�� 
	}
	return 0;
}

