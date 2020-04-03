#include<iostream>
#include<cstring>
#include<vector> 
using namespace std;


//判斷是否為英文字母 
#define isalpha(k) ((k>='A'&&k<='Z')||(k>='a'&&k<='z'))

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int K,E,set=1,k;
	while(cin>>K>>E)
	{
		string keyword[K],excuse[E],word;
		int keyword_in_excuse=0,index=0,max=0;
		vector<int> worst_excuse_id;
		for(int i=0;i<K;i++)
			cin>>keyword[i];

		cin.get();//吃掉換行 
		
		//找到最爛的那些藉口 
		while(index<E)
		{
			/*
			是字母->丟進一個字串
			不是字母->判斷字串是不是關鍵字
			換行、EOF->判斷最多關鍵字的藉口 
			*/
			k=cin.get();
			excuse[index]+=(char)k;
			if(isalpha(k))
				word+=(char)(k>='a'?k:k-'A'+'a');
			else
			{
				//判斷word是不是關鍵字 
				for(int i=0;i<K;i++)
				{
					if(word==keyword[i])
					{
						keyword_in_excuse++;
						break;
					}
				}
				
				//如果excuse[index]出現的關鍵字最多,記錄下來 
				if(k=='\n'||k==EOF)
				{
					//*test*/cout<<keyword_in_excuse<<endl;
					if(keyword_in_excuse==max)//出現一樣多的就丟進去
						worst_excuse_id.emplace_back(index);
					else if(keyword_in_excuse>max)//出現更多的就清除之前的紀錄，更新
					{
						worst_excuse_id.clear();
						worst_excuse_id.emplace_back(index);
						max=keyword_in_excuse;
					}
					keyword_in_excuse=0;
					index++;
				}
				word.clear();//word清空,準備紀錄下一筆
			}
		}
		
		//輸出 
		cout<<"Excuse Set #"<<set++<<'\n';
		for(unsigned int i=0;i<worst_excuse_id.size();i++)
			cout<<excuse[worst_excuse_id[i]];
		cout<<'\n';
	}
	return 0;
}

