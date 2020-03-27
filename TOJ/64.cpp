#include<iostream>
using namespace std;

#define sixteentoten(k) (k>='0'&&k<='9') ? k-'0' : k-'A'+10;
string stringxor(string A,string B)
{
	string C;
	int a,b;
	for(int i=0;i<A.size();i++)
	{
		a=sixteentoten(A[i]);
		b=sixteentoten(B[i]);
		C.append(1, (a^b)>=10 ? (a^b)-10+'A' : (a^b)+'0' );
	}
	return C;
}

int main()
{
	//原字串T:72個16進位 
	string 
	TA="207A35304765D69D9670F53856584E952BCDE2F8CA939CC01F82840E2934071EC91F7058",
	TB="76EC54D8C05EB5FB53436FC2E0C457339DDBFA31BA42B8707EDE807DBBA6D0C6905419B4",
	TAB="FD34A487207AC50873EF2AB01243AEF677D4B40ADD7A82F1C9FFB0B2394F7199F590DA97",
	B=stringxor(TA,TAB),
	A=stringxor(TB,TAB),
	T=stringxor(TB,B),
	truth;
	
	cout<<A<<endl;
	cout<<B<<endl;
	
	/*
	string
	ta=stringxor(T,A),
	tab=stringxor(ta,B),
	tb=stringxor(tab,A),
	t=stringxor(tb,B);
	cout<<(ta==TA)<<(tab==TAB)<<(tb==TB)<<(t==T)<<endl;*/
	
	//cout<<T<<endl;
	for(int i=0,t1,t2;i<T.size();i+=2)
	{
		t1=sixteentoten(T[i]);
		t2=sixteentoten(T[i+1]);
		truth.append(1, (t1*16+t2));
	}
	//cout<<truth<<endl;
	return 0;
}
