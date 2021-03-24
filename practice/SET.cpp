//https://github.com/liaojason2/vscode-cpp-for-windows#include<iostream>
#include<iostream>
using namespace std;

#define n 100001

int division[n];//每個人的分組 

//初始化，每個人自己一組 
inline void Init(int k)
{
	for(int i=0;i<k;i++)
		division[i]=i;
}

//尋找a的組別 
inline int find (int a)
{
	return division[a]==a ? a : division[a]=find(division[a]);
	/*
	這樣也可以，但相比上面大量執行時會較慢 
	return division[a]==a ? a : find(division[a]);
	*/
}

//將a,b兩人的組別合併為b組別 
inline void Union (int a,int b)
{
	//不用將全部同團體的都改為b的組別，
	//只要改變a組別的頭頭位置就好，之後用find就會找到 
	division[find(a)]=find(b);
}

//判斷兩個人的組別是否一樣 
inline bool same (int a,int b){
	return find(a)==find(b);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
    cin>>T;
    while(T--)
    {
        int N,M; 
        cin>>N>>M;
        Init(N+1);//初始化 
        
		while(M--)
        {
            int a,b;
            cin>>a>>b;
            //將b組別的人移至a組 
            Union(b,a);
        }
        
        for(int i=1;i<=N;i++)
			cout<<find(division[i])<<'\n';
    }
	return 0;
}

