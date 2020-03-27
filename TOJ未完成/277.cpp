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
		
		int l=0,r=n.size()-1,pl,pr;//���k�y�СA�����^�媺���k�y�� 
		bool nines;//�P�_�����^��O�_����9 
		
		//�򥻼ƾ� 
		pl=(n.size()%2?n.size()/2:n.size()/2-1);
		pr=n.size()/2;
		nines=(n[pl]=='9'&&n[pr]=='9'?1:0);//�P�_�����O�_��9�^��(�i��ݭn�i�쬰0) 
		
		while(pl>l)//�o�줤���^�媺�y�Ц�m
		{
			if(nines)
			{
				if(!(n[pl]=='9'&&n[pr]=='9'))break;
			}
			else if(n[pl]!=n[pr])break;
			pl--;
			pr++;
		}
		
		//�p�G��곣�O9�A��X100...001�A�h�@�Ӧ�Ƭ��S�� 
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
			if(l==pl&&r==pr)//�p�G�I�줤���^��A�i�H�����o�����G 
			{
				if(n[r]>=n[l])//�p�G��>=�Y:�ݭn�i�� 
				{
					if(nines)//�p�G�����^�嬰9�A�ݭn��9�令0�A�Y�i�� 
					{
						string temp;
						n[l]++;
						temp.append(n,0,l+1);
						temp.append(r-l-1,'0');
						temp.append(n,r,n.size()-r);
						n.assign(temp,0,temp.size());
					}
					else//�̤������i��N�n 
					{
						if(n.size()%2)n[n.size()/2]++;
						else n[n.size()/2]=++n[n.size()/2-1];
					}
				}
				n[r]=n[l];
				break;
			}
			//��=�Y 
			n[r]=n[l];
			l++;
			r--;
		}
		cout<<n<<'\n';//��X 
	}
	return 0;
}

