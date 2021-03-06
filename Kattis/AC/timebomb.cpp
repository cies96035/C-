#include<iostream>
using namespace std;

const string num[6]=
{
    "***   * *** *** * * *** *** *** *** ***",
    "* *   *   *   * * * *   *     * * * * *",
    "* *   * *** *** *** *** ***   * *** ***",
    "* *   * *     *   *   * * *   * * *   *",
    "***   * *** ***   * *** ***   * *** ***"
};
string Num[6];

int GetNum(int s)
{
    for(int i = 0; i < 10; i++)
    {
        bool flg = 1;
        for(int j = 0; flg && j < 5; j++)
            for(int k = 0; flg && k < 3; k++)
                if(Num[j][s + k] != num[j][i * 4 + k])
                    flg = 0;
        if(flg)
            return i;
    }
    return -1;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 5; i++)
        getline(cin, Num[i]);
    
    int p = 0;
    int t;
    for(int i = 0; i < Num[0].size(); i+=4)
    {
        t = GetNum(i);
        if(t == -1)
            break;
        p += t;
    }
    if(!(t & 1) && !(p % 3)){
        cout << "BEER!!\n";
    }else{
        cout << "BOOM!!\n";
    }
    return 0;
}