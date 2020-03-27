#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t;
	cin>>t;
	while(t--)
	{
		string n;
		cin>>n;
		
		int l=0,r=n.size()-1,pl,pr;//左右座標，中間回文的左右座標 
		bool nines;//判斷中間回文是否都為9 
		
		//基本數據 
		pl=(n.size()%2?n.size()/2:n.size()/2-1);
		pr=n.size()/2;
		nines=(n[pl]=='9'&&n[pr]=='9'?1:0);//判斷中間是否為9回文(可能需要進位為0) 
		
		while(pl>l)//得到中間回文的座標位置
		{
			if(nines)
			{
				if(!(n[pl]=='9'&&n[pr]=='9'))break;
			}
			else if(n[pl]!=n[pr])break;
			pl--;
			pr++;
		}
		
		//如果整串都是9，輸出100...001，多一個位數為特例 
		if(nines&&pl==0&&n[pl]=='9')
		{
			string output;
			output.append(1,'1');
			output.append(n.size()-1,'0');
			output.append(1,'1');
			n.assign(output,0,output.size());
			l=r+1; 
		}
		
		while(l<=r)
		{
			if(l==pl&&r==pr)//如果碰到中間回文，可以直接得知結果 
			{
				if(n[r]>=n[l])//如果尾>=頭:需要進位 
				{
					if(nines)//如果中間回文為9，需要把9改成0，頭進位 
					{
						string temp;
						n[l]++;
						temp.append(n,0,l+1);
						temp.append(r-l-1,'0');
						temp.append(n,r,n.size()-r);
						n.assign(temp,0,temp.size());
					}
					else//最中間的進位就好 
					{
						if(n.size()%2)n[n.size()/2]++;
						else n[n.size()/2]=++n[n.size()/2-1];
					}
				}
				n[r]=n[l];
				break;
			}
			//尾=頭 
			n[r]=n[l];
			l++;
			r--;
		}
		cout<<n<<'\n';//輸出 
	}
	return 0;
}

