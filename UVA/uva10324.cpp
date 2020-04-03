#include<iostream>
using namespace std;

/*
預處理O(n) 每筆詢問O(logn)
相比直接每筆詢問掃過一次O(n)好得多
第一眼看到就直接寫線段樹 
只是後來想想這題還有更快且更好寫的方法... 
*/
//基本上就是很基本的線段樹，也沒有更新，只要建樹搜尋就好 

#define LC(root) root*2 //左子節點 
#define RC(root) root*2+1 //右子節點 


int state[4000000];
/*
紀錄狀態用:
0此區段皆為0,
1此區段皆為1,
2此區段混雜0和1 
*/ 
//最多有n*4個區段，最少n*2-1，題目長度最長1000000

string zero_and_one;
//用來記錄01序列 

//建樹，樹的內容是判斷序列每一個區間的狀態(皆為0,皆為1,混砸) 
void build(int root,int L,int R)
{
	//最底層時終止遞迴，區間L==R的那個節點，序列內容只有一個(就是第L個) 
	if(L==R)
	{
		state[root]=zero_and_one[L]-'0';
		return;
	}
	
	//拆成兩份往下遞迴，左區間和右區間 
	int M=(L+R)/2;
	build(LC(root),L,M);
	build(RC(root),M+1,R);
	
	//遞迴完後，判斷此區間的狀態屬於哪種
	//左區間右區間都是1或0的話，就代表此區間狀態是1或0，其他狀況的話就是混雜狀態的2 
	state[root]=(state[LC(root)]==state[RC(root)]?state[LC(root)]:2);
	return;
}

int l,r,state_in_query;
//搜尋時，用來記錄欲搜尋的左邊界，右邊界
//還有紀錄這個範圍的狀態(-1代表未記錄過) 

//搜尋線段樹 
void query(int root,int L,int R)
{
	//如果此節點區段完全在搜尋範圍內
	//則加入判斷
	if(l<=L&&r>=R)
	{
		//如果未記錄過，先給定一個初始值 
		if(state_in_query==-1)state_in_query=state[root];
		//如果搜尋結果出現不一樣的值，則記錄成混雜狀態 
		else state_in_query=(state[root]==state_in_query?state_in_query:2);
		return;
	}
	if(state_in_query!=2)//可以不加，主要在加速用，如果已經出現混雜的結果，可以不用再繼續搜尋了 
	{
		int M=(L+R)/2; 
		if(l<=M)query(LC(root),L,M);
		if(r>M)query(RC(root),M+1,R);	
	}
}

int main()
{
	//io優化 
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int Case=1;//紀錄第幾筆測資 
	while(cin>>zero_and_one)//多筆測資 
	{
		cout<<"Case "<<Case++<<":\n";
		int ZAOend=zero_and_one.size()-1,Q;
		
		//root固定是1
		//建樹的範圍是整個字串，也就是0~字串的尾端 
		build(1,0,ZAOend);
		
		//搜尋次數 
		cin>>Q;
		while(Q--)
		{
			//搜尋左邊界、右邊界 
			cin>>l>>r;
			//注意有可能左>右 
			if(l>r)swap(l,r);
			//搜尋狀態設為未記錄過 
			state_in_query=-1;
			//一樣，搜尋的root固定是1,搜尋的範圍是整個序列 
			query(1,0,ZAOend);
			
			//判斷狀態，輸出結果 
			if(state_in_query==2)cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
	return 0;
}

