#include<iostream>
#include<cstring>
#include<queue> 
using namespace std;

#define card_size 34//共34種牌

//紀錄牌類名字，方便輸出 
const string card_name[card_size]=
{"1T","2T","3T","4T","5T","6T","7T","8T","9T",
"1S","2S","3S","4S","5S","6S","7S","8S","9S",
"1W","2W","3W","4W","5W","6W","7W","8W","9W",
"DONG","NAN","XI","BEI","ZHONG","FA","BAI"};

//紀錄正在聽甚麼牌、以及是否在聽牌 
bool ans[card_size],isnt_ready=1;

//一個紀錄每個card數量及總數的struct 
struct Card
{
	int num[card_size],all_num=13;
}card;

inline void Init()//初始化 (用於每次結束，把卡片數量歸零避免判斷到上次的) 
{
	memset(card.num,0,sizeof(card.num));
	memset(ans,0,sizeof(ans));
	card.all_num=13;
	isnt_ready=1;
	return;
}

//把字串轉成卡片ID，再記錄該ID的數量 (用於一開始輸入，轉換成可用資料) 
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
	
	int Case=1;//第幾筆測資
	string input_card[13];//牌組 
	while(cin>>input_card[0])
	{
		if(input_card[0]=="0")break;
		
		//紀錄牌組內容 
		string_to_card_num(input_card[0]);
		for(int i=1;i<13;i++)
		{
			cin>>input_card[i];
			string_to_card_num(input_card[i]);
		}
		
		//BFS用佇列，把card和已吃過eye的丟進去 
		queue<Card> toBFS;
		toBFS.push(card);
		
		//題目需求應該不能超出一次eye，所以要在BFS外丟eye 
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
		
		//開始BFS
		//這裡有個問題，沒有紀錄已走過的地方，所以會搜尋較多次，時間較長，待改善 
		while(!toBFS.empty())
		{
			Card x=toBFS.front();
			toBFS.pop();
			
			//剩1張，可以用eye作為聽牌 
			if(x.all_num==1) 
				for(int i=0;i<card_size;i++)
					if(x.num[i])
						ans[i]=true;
			
			//剩2張，可能可以用pong或chow或都不是作為聽牌 
			if(x.all_num==2)
			{
				for(int i=0;i<card_size;i++)
				{
					if(x.num[i]==2)//當有某個種類有2張時，可以達成pong 
					{
						ans[i]=true;
						break;
					}
					//如果可以達成特定3個連續，可以達成chow 
					else if(i<27&&i%9>1&&x.num[i]+x.num[i-1]+x.num[i-2]==2) 
						ans[x.num[i]?x.num[i-1]?i-2:i-1:i]=true;
				} 
			} 
			for(int i=0;i<card_size;i++)
			{
				if(x.num[i]>=3)//pong
				{
					x.num[i]-=3;//把pong的丟進queue 
					x.all_num-=3;//總數一樣扣掉 
					toBFS.push(x);
					x.num[i]+=3;//加回來，繼續之後的判斷 
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
			//*測試用*/for(int i=0;i<card_size;i++)cout<<x.num[i]<<' ';cout<<endl;
		}
		
		//輸出部分 
		cout<<"Case "<<Case++<<':';
		for(int i=0;i<card_size;i++)
			if(ans[i]&&card.num[i]!=4)
			{
				cout<<' '<<card_name[i];
				isnt_ready=0;
			}
		if(isnt_ready)cout<<" Not ready";
		cout<<'\n';
		
		Init();//初始化 
	}
	return 0;
}

