#include<iostream>
#include<algorithm>
using namespace std;
struct Line
{
	int L,R;
};
bool cmp(Line x,Line y)
{
	return x.L<y.L;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N;
	cin>>N;
	Line line[N];
	for(int i=0;i<N;i++)
		cin>>line[i].L>>line[i].R;
	sort(line,line+N,cmp);
	int left=line[0].L,right=line[0].R;
	for(int i=1;i<N;i++)
	{
		if(line[i].L>right)
		{
			cout<<left<<' '<<right<<'\n';
			left=line[i].L;
			right=line[i].R;
		}
		else
			if(line[i].R>right)right=line[i].R;
	}
	cout<<left<<' '<<right<<'\n';
	return 0;
}

