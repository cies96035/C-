#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//可自行把queue改成queue觀察，基本上就由BFS變成DFS了

#define N 6 //6個點

int main()
{
	//以TOJ9第一筆測資為範例:(0,5)(0,1)(5,4)(2,3)(3,0)(4,1)(1,2)
	//紀錄雙向圖:link[a][b]=1時代表a往b是通的
	bool link[N][N] =
	{ {0,1,0,1,0,1},
	{1,0,1,0,1,0},
	{0,1,0,1,0,0},
	{1,0,1,0,0,0},
	{0,1,0,0,0,1},
	{1,0,0,0,1,0} };
	//紀錄每個點是否走過(避免一直重複走會無限迴圈TLE
	bool visited[N] = { 0,0,0,0,0,0 };
	//紀錄準備要前往的佇列
	queue<int> togo, ctogo;

	togo.push(4);//準備從第4點開始出發
	visited[4] = 1;//第4點已被搜尋過
	cout << "***current togo: " << togo.front() << endl << endl;

	while (!togo.empty())//直到沒有地方可以前往為止
	{
		int now = togo.front();
		togo.pop();

		cout << "now search points which is beside " << now << endl << endl;

		//把所有跟現在這點相連的都丟進準備前往的佇列
		for (int i = 0; i < N; i++)
			if (link[now][i])
			{
				if (visited[i])
				{
					cout << i << " has been search, without push in queue" << endl;
					//丟進佇列的話會造成此點重複搜尋而產生錯誤
				}
				else
				{
					cout << i << "has been push in queue, and " << i << " has been search" << endl;
					togo.push(i);
					visited[i] = 1;
				}
			}
		cout << endl << "***current togo queue:";
		ctogo = togo;
		while (!ctogo.empty())
		{
			cout << ctogo.front() << ' ';
			ctogo.pop();
		}
		cout << endl << endl;
	}
	cout << "the queue is empty, break the loop" << endl;
	//一般題目會設置一個結束條件，如果達成就直接break跳出迴圈
	//像下坡車的條件是到達最低點，如果沒有達到break條件就是無法到達最低點

	return 0;
}
