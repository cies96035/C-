#include <iostream>
#include <algorithm>
using namespace std;
const int n1 = 7, n2 = 5;
// 為了實作方便，從陣列的第1格開始存入序列。
string s1 = "2579312";
string s2 = "35328";
int length[7+1][5+1];   // DP表格
 
void LCS()
{
    // 初始化：當s1或s2是空集合，則LCS是空集合。
    // length[x][0] = length[0][x] = 0;
    for (int i=0; i<=n1; i++) length[i][0] = 0;
    for (int j=0; j<=n2; j++) length[0][j] = 0;
 
    // 填表格：依照遞迴公式
    for (int i=0; i<n1; i++)
    {
        for (int j=0; j<n2; j++)
        {
            if (s1[i] == s2[j])
                // +1是因為e1的長度為1
                length[i+1][j+1] = length[i][j] + 1;
            else
                length[i+1][j+1] = max(length[i][j+1],
                                   length[i+1][j]);
            cout<<length[i+1][j+1]<<' ';
        }
        cout<<endl;
	}
 
    cout << "LCS的長度是" << length[n1][n2];
}
int main()
{
	LCS();
	return 0;
}

