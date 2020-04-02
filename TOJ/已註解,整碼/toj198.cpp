/*
理論上非正解
速度比他人慢很多
但還是能過 
*/ 

#include<iostream>
#include<cstring>
using namespace std;

//將英文以外的去掉，並將英文用成小寫以利判斷 
string strtouse(string k)
{
	string d;
	int klen=k.size();
    for(int h=0;h<klen;h++)
    {
        //判斷是否為英文(只取英文)
        if((k[h]>='A'&&k[h]<='Z')||(k[h]>='a'&&k[h]<='z'))
        {
            //是的話一律用小寫編進d字串 
            d+=tolower(k[h]);
        }
    }
    return d;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string a,b;
    while(getline(cin,a))
    {
        getline(cin,b);
        a=strtouse(a);
        b=strtouse(b);
        /*
		a.find(b,num)，cstring裡的函數 
		從a字串的第num位找b字串
		找到回傳位置，找不到回傳-1 
		*/ 
        if(a.find(b,0)!=-1)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
