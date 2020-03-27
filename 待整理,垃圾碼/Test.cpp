#include<iostream>
#include<cmath>
using namespace std;
const int n1 = 7, n2 = 5;
// ���F��@��K�A�q�}�C����1��}�l�s�J�ǦC�C
int s1[7+1] = {0, 2, 5, 7, 9, 3, 1, 2};
int s2[5+1] = {0, 3, 5, 3, 2, 8};
int length[7+1][5+1];   // DP���
 
void LCS()
{
    // ��l�ơG��s1��s2�O�Ŷ��X�A�hLCS�O�Ŷ��X�C
    // length[x][0] = length[0][x] = 0;
    for (int i=0; i<=n1; i++) length[i][0] = 0;
    for (int j=0; j<=n2; j++) length[0][j] = 0;
 
    // ����G�̷ӻ��j����
    for (int i=1; i<=n1; i++)
    {
        for (int j=1; j<=n2; j++)
        {
            if (s1[i] == s2[j])
                // +1�O�]��e1�����׬�1
                length[i][j] = length[i-1][j-1] + 1;
            else
                length[i][j] = max(length[i-1][j],
                                   length[i][j-1]);
            cout<<length[i][j]<<' ';
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

