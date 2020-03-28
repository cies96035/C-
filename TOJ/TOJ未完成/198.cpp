#include<iostream>
#include<cstring>
using namespace std;

int failure[100000];//¬ö¿ýfailure­È 
string keyword,word;

void get_failure()
{
	int ws=word.size(),i=1,flen=0;
	failure[0] = 0;
	while(i<ws)
	{
		if(word[i]==word[flen])
			failure[i++] = ++flen;
		else
		{
			if(flen!=0)
				flen=failure[flen-1];
			else
				failure[i++]=0;
		}
	}
}

string strtouse(string k)
{
    string d;
    int klen=k.size();
    for(int h=0;h<klen;h++)
    {
        if((k[h]>='A'&&k[h]<='Z')||(k[h]>='a'&&k[h]<='z'))
        {
            d+=tolower(k[h]);
        }
    }
    return d;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(getline(cin,keyword))
    {
    	bool flag=0;
        getline(cin,word);
        keyword=strtouse(keyword);
        word=strtouse(word);
        
        get_failure();
        
        for(int i=0,j=0;i<keyword.size();)
        {
        	if(keyword[i]==word[j])
        	{
        		i++;
        		j++;
        		if(j==word.size())
        		{
        			flag=1;
        			break;
				}
			}
			else
			{
				if(j!=0)
					j=failure[j-1];
				else 
					i++;
			}
		}

        if(flag)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
