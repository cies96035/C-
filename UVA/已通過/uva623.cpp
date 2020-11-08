#include<iostream>
#include<cstring>
using namespace std;
#define maxL 3300
#define maxn 1020

class BIGNUM
{
    protected:
        int n[maxL];
        int len;
        void string_to_BIGNUM(string s)
        {
            len=s.size();
            for(int i=0;i<s.size();i++)
                n[i]=s[i]-'0';
            for(int i=0,j=s.size()-1;i<j;i++,j--)
                swap(n[i],n[j]);
            return;
        }
        void update_Len()
        {
            int i=maxL-1;
            for(;i>=0;i--)
            {
                if(n[i]!=0)
                {
                    len=i+1;
                    return;
                }
            }
            len=1;
            return;
        }
    public:
        BIGNUM(string s)
        {
            string_to_BIGNUM(s);
        }
        BIGNUM()
        {
            memset(this->n,0,sizeof(this->n));
            len=1;
        }
        BIGNUM(int i)
        {
            int_to_BIGNUM(i);
        }
        void int_to_BIGNUM(int i)
        {
            int index=0;
            while(i)
            {
                this->n[index++]=i%10;
                i/=10;
            }
            len=index;
            return;
        }
        BIGNUM operator *(BIGNUM b)
        {
            BIGNUM c;
            for(int i=0;i<this->len;i++)
            {
                for(int j=0;j<b.len;j++)
                {
                    c.n[i+j]+=this->n[i]*b.n[j];
                }
            }
            for(int i=0;i<maxL;i++)
            {
                if(c.n[i]>=10)
                {
                    c.n[i+1]+=c.n[i]/10;
                    c.n[i]%=10;
                }
            }
            c.update_Len();
            return c;
        }
        void output()
        {
            for(int i=len-1;i>=0;i--)
                cout<<this->n[i];
            cout<<'\n';
            return;
        }
}num[maxn];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    num[0].int_to_BIGNUM(1);
    for(int i=1;i<maxn;i++)
        num[i]=num[i-1]*BIGNUM(i);

    while(cin>>n)
    {
        cout<<n<<"!\n";
        num[n].output();
    }
    return 0;
}