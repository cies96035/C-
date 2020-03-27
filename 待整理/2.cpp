#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int maxN=5001;
int set[maxN];
void Init(int k){for(int i=0;i<k;i++)set[i]=i;}
int Find(int x){return set[x]==x?x:set[x]=Find(set[x]);}
void Union(int x,int y){set[Find(x)]=Find(y);}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n,m,ans=0;
	cin>>n>>m;
	
	int record[n]={0};//�����P�C���I�۾F���ƶq 
	vector<int> linked[n];//�����P�C���I�۾F���I 
	memset(linked,0,sizeof(linked));
	Init(n);//�C��set 
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		Union(--a,--b);
		record[a]++;
		record[b]++;
		linked[a].push_back(b);
		linked[b].push_back(a);
	}
	
	bool visited[n]={0};
	for(int i=0;i<n;i++)
	{
		if(!visited[i])//�B�z�C��set 
		{
			vector<int> sameset;
			for(int j=0;j<n;j++)
			{
				if(Find(i)==Find(j))//�Y�b�P�@��set 
				{
					visited[j]=1;//True�аO�קK���ƭp�� 
					sameset.push_back(j);//��ivector�i��o�����P�_ 
				}
			}
			
			int Max=0,minD=0,tmp,erasenum=0;
			bool iserase[n]={0};
			do
			{
				tmp=minD;
				minD=2e9;
				vector<int> minid;
				for(int j=0;j<sameset.size();j++)
				{
					if(iserase[sameset[j]])continue;//�p�G�o���I�w�Q�����A���L 
					if(minD>=record[sameset[j]])
					{
						if(minD>record[sameset[j]])
							minid.clear();
						minD=record[sameset[j]];
						minid.push_back(sameset[j]);
					}
				}
				Max=max(Max,int(minD*(sameset.size()-erasenum)));
				
				for(int j=0;j<minid.size();j++)//��Ҧ��̤p�Ȫ��I���� 
				{
					for(int k=0;k<linked[minid[j]].size();k++)//���䲾�� 
						record[linked[minid[j]][k]]--;
					iserase[minid[j]]=1;//�����o���I 
					erasenum++;//�����I���ƶq�W�[ 
				}
			}while(minD>tmp&&sameset.size()>erasenum);
			if(Max>ans)ans=Max;
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}

