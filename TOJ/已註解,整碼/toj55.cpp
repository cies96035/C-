#include<iostream>
#include<algorithm> 
using namespace std;

int main()
{
    //本題多個輸入，需要加速 
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,M,ask;
    
    //輸入整數N 
    cin>>N;
    //輸入N個歌曲編號 
    int A[N];
    for(int h=0;h<N;h++)cin>>A[h];
    
    //照順序排好，才能使用之後的二分搜尋 
    sort(A,A+N);
    
    //輸入整數M 
    cin>>M;
    //執行M次 
    while(M--)
    {
        //輸入想詢問的歌曲編號 
        cin>>ask;
        
        //ans為要輸出的答案，其他是二分搜尋要用的
        //每次迴圈調整為初始值 
        int ans=0,max=N,min=0,mid;
        
        //二分搜尋的程式碼 
        while(max>=min)
        {
            mid=(max+min)/2;
            if(A[mid]<ask)
                min=mid+1;
            else if(A[mid]>ask)
                max=mid-1;
            else
            {
                /*
                進入else這次找到了ask的位置在mid 
                min~max一定有數個ask的值 
                */
                //符合ask的值加入答案 
                for(int H=min;H<=max;H++)
                {
                    if(ask==A[H])ans++;
                }
                //離開迴圈 
                break;
            }
        }
        //輸出答案 
        cout<<ans<<"\n";
    }
    return 0;
}
