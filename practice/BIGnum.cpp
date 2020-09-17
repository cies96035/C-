#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

typedef long long ll;
const ll Maxlen=20000,Base=1000000,Base_zero=6;
bool Test_Mode=1;
class BIGNUM
{
    protected:
        //num:store all number
        //length:store used numsize
        //sign:record positive or negative, if BIGNUM==ZERO, sign=0(positive)
        ll num[Maxlen];
        unsigned int length;
        bool sign;
    public:

    //INPUT and OUTPUT
    friend istream &operator>>(istream &In,BIGNUM &n);
    friend ostream &operator<<(ostream &Out,const BIGNUM &n);

    /******************CONSTRUCTOR******************/

    //Initial (ZERO)
    BIGNUM()
    {
        this->Init();
    }
    
    //convert a string to BIGNUM
    BIGNUM(const string &s)
    {
        this->convert_string_to_BIGNUM(s);
    }

    //Copy BIGNUM
    BIGNUM(const BIGNUM &b)
    {
        this->Init();
        *this=b;
    }
    
    /******************CONSTRUCTOR******************/

    /********************METHOD********************/

    //ZERO
    void   Init()
    {
        this->sign=0;
        memset(this->num,0,sizeof(this->num));
        this->length=1;
        return;
    }
    
    //check if the value is zero,its sign is positive
    void   only_one_zero()
    {
        if(this->num[0]==0&&this->length==1)
            this->sign=0;
        return;
    }

    //update this->length ,and return it
    int    getlength()
    {
        int len=Maxlen-1;
        while(len>0&&this->num[len]==0)
            len--;
        this->length=len+1;
        only_one_zero();
        return this->length;
    }

    //convert one str to long long
    ll     string_to_little_num(string str)
    {
        ll result=0;
        for(unsigned int i=0;i<str.size();i++)
            result=result*10+str[i]-'0';
        return result;
    }

    //convert one str to BIGNUM
    void   convert_string_to_BIGNUM(string str)
    {
        this->Init();//Initial

        int i=0,j=str.size()-Base_zero;

        //負數
        if(str[0]=='-')
        {
            j--,this->sign=1;
            str[0]='0';
        }
        for(;j>=0;i++,j-=Base_zero)
            this->num[i]=string_to_little_num(str.substr(j,Base_zero));

        this->num[i]=string_to_little_num(str.substr(0,str.size()%Base_zero));

        this->getlength();
        return;
    }
    
    void   Shift(int k)
    {
        if(k>0)
        {
            for(int i=this->length-1;i>=0;i--)
                this->num[i+k]=this->num[i];
            for(int i=0;i<k;i++)
                this->num[i]=0;
        }
        /*
        else
        {
            for(int i=0;i<this->length;i++)
            {
            }
        }*/
    }
    
    //POW
    BIGNUM Pow_INT(const BIGNUM &b) const
    {
        BIGNUM base("1");
        BIGNUM m(*this);
        int n=b.num[0];
        while(n)
        {
            if(n%2)
                base*=m;
            m*=m;
            n/=2;
        }
        return base;
    }
    /********************METHOD********************/
    
    /********************CMP_OPERATOR********************/

    bool   operator== (const BIGNUM &b) const
    {
        if(this->sign!=b.sign)
            return false;
        if(this->length!=b.length)
            return false;
        for(unsigned int i=0;i<this->length;i++)
            if(this->num[i]!=b.num[i])
                return false;
        return true;
    }

    bool   operator>  (const BIGNUM &b) const
    {
        if(this->sign!=b.sign)
            return this->sign<b.sign;
        if(*this==b)
            return false;
        
        bool unsign_ans=0;
        
        if(this->length!=b.length)
            unsign_ans = this->length > b.length;
        else
            for(int i=this->length-1;i>=0;i--)
                if(this->num[i] != b.num[i])
                {
                    unsign_ans=(this->num[i] > b.num[i]);
                    break;
                }
        return this->sign^unsign_ans;
    }

    bool   operator>= (const BIGNUM &b) const
    {
        return *this>b||*this==b;
    }

    bool   operator<  (const BIGNUM &b) const
    {
        return !(*this>=b);
    }
    
    bool   operator<= (const BIGNUM &b) const
    {
        return !(*this>b);
    }

    bool   operator!= (const BIGNUM &b) const
    {
        return !(*this==b);
    }
    
    /********************CMP_OPERATOR********************/
    
    /********************OPERATOR********************/
    void operator=  (const BIGNUM &b)//a=b
    {
        this->length=b.length;
        for(unsigned int i=0;i<length;i++)
            this->num[i]=b.num[i];
        this->sign=b.sign;
        return;// *this;
    }

    BIGNUM operator+  (const BIGNUM &b) const//a+b
    {
        BIGNUM L(*this),S(b);
        BIGNUM c;

        int Biggerlen=max(this->length,b.length)+1;
        bool carry=0;
        //if same sign -> keep same sign ,and add together
        if(this->sign==b.sign)
        {
            for(int i=0;i<Biggerlen;i++)
            {
                c.num[i]=this->num[i]+b.num[i]+carry;
                carry=c.num[i]/Base;
                c.num[i]%=Base;
            }   
            c.sign=this->sign;
        }
        else//one positive one negative
        {
            bool swapflg=0;
            L.sign=S.sign=0;
            if(L<S)
            {
                swap(L,S);
                swapflg=1;
            }
            //sub
            for(int i=0;i<Biggerlen;i++)
            {
                c.num[i]=L.num[i]-carry-S.num[i];
                if(c.num[i]<0)
                {
                    c.num[i]+=10;
                    carry=1;
                }
                else
                    carry=0;
            }

            c.sign=(this->sign)^(swapflg);
            
        }
        c.getlength();
        return c;
    }

    BIGNUM operator-  (const BIGNUM &b) const//a-b
    {
        BIGNUM b_COPY(b);
        b_COPY.sign^=1;
        return *this+b_COPY;
    }
    
    BIGNUM operator*  (const BIGNUM &b) const//a*b
    {
        BIGNUM c;
        int Maxlen=this->length+b.length;
        int carry=0;
        for(unsigned int i=0;i<this->length;i++)
            for(unsigned int j=0;j<b.length;j++)
            {
                c.num[i+j]+=this->num[i]*b.num[j];
                if(c.num[i+j]>Base)
                {
                    c.num[i+j+1]+=c.num[i+j]/Base;
                    c.num[i+j]%=Base;
                }
            }
        for(int i=0;i<Maxlen;i++)
        {
            c.num[i+1]+=c.num[i]/Base;
            c.num[i]%=Base;
        }
        c.sign=this->sign^b.sign;
        c.getlength();
        return c;
    }

    /*
    BIGNUM operator/ (const BIGNUM &b) const//a/b
    {
        BIGNUM dived(*this),div(b);
        BIGNUM ans;
        while(dived>div)
        {
            return 
        }
        
    }*/

    void operator+= (const BIGNUM &b)//a+=b
    {
        *this = *this + b;
        return;
    }

    void operator-= (const BIGNUM &b)//a+=b
    {
        *this = *this - b;
        return;
    }

    void operator*= (const BIGNUM &b)//a*=b
    {
        *this = *this * b;
        return;
    }
    
    /********************OPERATOR********************/
};


/********************IO_OPERATOR********************/

ostream &operator<<(ostream &Out,const BIGNUM &n)//cout<<BIGNUM()
{
    if(n.sign)Out<<'-';
    Out<<n.num[n.length-1];
    for(int i=n.length-2;i>=0;i--)
        Out<<setw(Base_zero)<<setfill('0')<<n.num[i];
    return Out;
}

istream &operator>>(istream &In,BIGNUM &n)//cin>>BIGNUM()
{
    string s;
    In>>s;
    n.convert_string_to_BIGNUM(s);
    return In;
}

/********************IO_OPERATOR********************/

void TEST(BIGNUM &a,BIGNUM &b,string op)
{
    string TF[2]={"False","True"};
    if(op==">"||Test_Mode)
        cout<<a<< " > " <<b<< " = " << TF[(a>b)] <<endl;
    if(op==">="||Test_Mode)
        cout<<a<< " >= " <<b<< " = " << TF[(a>=b)] <<endl;
    if(op=="=="||Test_Mode)
        cout<<a<< " == " <<b<< " = " << TF[(a==b)] <<endl;
    if(op=="<"||Test_Mode)
        cout<<a<< " < " <<b<< " = " << TF[(a<b)] <<endl;
    if(op=="<="||Test_Mode)
        cout<<a<< " <= " <<b<< " = " << TF[(a<=b)] <<endl;
    if(op=="!="||Test_Mode)
        cout<<a<< " != " <<b<< " = " << TF[(a!=b)] <<endl;
    if(op=="+"||Test_Mode)
        cout<<a<< " + " <<b<< " = " << a+b <<endl;
    if(op=="-"||Test_Mode)
        cout<<a<< " - " <<b<< " = " << a-b <<endl;
    if(op=="*"||Test_Mode)
        cout<<a<< " * " <<b<< " = " << a*b <<endl;
    if(op=="^"||Test_Mode)
        cout<<a<< " ^ " <<b<< " = " <<a.Pow_INT(b) <<endl;
    return;
}

int main()
{
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    
    BIGNUM a,b;
    string op;

    ifstream Inp("A.txt");
    ofstream Out("B.txt");
    Out<<1<<endl;
    while(Inp>>op>>a>>b)
    {
        if(op=="mul")
            Out<<a*b<<'\n'<<endl;
        else if(op=="pow")
            Out<<a.Pow_INT(b)<<'\n'<<endl;
        cout<<flush;
    }
    Inp.close();
    Out.close();
    /*
    while((Test_Mode?cin>>a>>b:cin>>a>>op>>b))
    {
        TEST(a,b,op);
    }*/
    return 0;
}