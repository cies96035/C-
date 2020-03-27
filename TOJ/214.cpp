#include<iostream>
using namespace std;
const string s[6]=
{
"[size=2]",
"[url=https:/",
"/www.pixiv.net/member_illust.php?illust_id=",
"&mode=medium][img=https:/",
"/pixiv.cat/",
".png][/url][/size]"};
 
//s0+date+s0+id+s2+id+s3
 
int main()
{
	string date,id;
	cin>>date>>id;
	cout<<s[0]<<date<<s[1]<<s[2]<<id<<s[3]<<s[4]<<id<<s[5]<<endl;
	return 0;
}
 
