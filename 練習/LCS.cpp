#include <iostream>
#include <algorithm>
using namespace std;
const int n1 = 7, n2 = 5;
// ���F��@��K�A�q�}�C����1��}�l�s�J�ǦC�C
string s1 = "2579312";
string s2 = "35328";
int length[7+1][5+1];   // DP���
 
void LCS()
{
    // ��l�ơG��s1��s2�O�Ŷ��X�A�hLCS�O�Ŷ��X�C
    // length[x][0] = length[0][x] = 0;
    for (int i=0; i<=n1; i++) length[i][0] = 0;
    for (int j=0; j<=n2; j++) length[0][j] = 0;
 
    // ����G�̷ӻ��j����
    for (int i=0; i<n1; i++)
    {
        for (int j=0; j<n2; j++)
        {
            if (s1[i] == s2[j])
                // +1�O�]��e1�����׬�1
                length[i+1][j+1] = length[i][j] + 1;
            else
                length[i+1][j+1] = max(length[i][j+1],
                                   length[i+1][j]);
            cout<<length[i+1][j+1]<<' ';
        }
        cout<<endl;
	}
 
    cout << "LCS�����׬O" << length[n1][n2];
}
int main()
{
	LCS();
	return 0;
}

