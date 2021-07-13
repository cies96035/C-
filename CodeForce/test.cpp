#include <bits/stdc++.h>
 
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro,...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro,nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro,nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro,nargs) macro ## nargs
#define DBN(...)        macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DBN1(a)         cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
 
#define endl '\n'
#define DBN1D(x) cerr<<#x<<endl;for(auto _:x){cerr<<_<<" ";}cerr<<endl
#define DBN2D(x) cerr<<#x<<endl;for(auto _:x){for(auto __:_){cerr<<__<<" ";}cerr<<endl;}cerr<<"------"<<endl
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp(x,y) make_pair(x,y)
#define mpp(w,x,y,z) mp(mp(w,x),mp(y,z))
using namespace std;
typedef long long loli;
typedef vector<loli> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef pair<loli,loli> pll;
typedef pair<pll,pll> pllll;
typedef vector<pll> vpll;
 
 
vl arr,st;
 
void build(int l,int r,int v){
    DBN(l,r,v);
    if(l==r-1){
        st[v]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*v+1);
    build(mid,r,2*v+2);
    st[v]=__gcd(st[2*v+1],st[2*v+2]);
}
int query(int L,int R,int l,int r,int v){
    // DBN(L,R,l,r,v);
    assert(R>L);
    if(l==L && R==r)
        return st[v];
    int mid=(l+r)/2;
    if(R<=mid)
        return query(L,R,l,mid,2*v+1);
    else if(L>=mid)
        return query(L,R,mid,r,2*v+2);
    else
        return __gcd(query(L,mid,l,mid,2*v+1),query(mid,R,mid,r,2*v+2));
}
void solve(){
 
    int n;
    cin>>n;
    arr.assign(2*n,0);
    st.assign(8*n,0);
    for(int i=0;i<n<<1;++i){
        if(i<n)
            cin>>arr[i];
        else
            arr[i]=arr[i-n];
    }
    build(0,2*n,0);
    //cout << "A";
    //DBN(query(1,3,0,2*n,0));
    int ans=0;
    int j=1;
    for(int i=0;i<n;++i){
        if(i==j)
            ++j;
        while(query(i,j,0,2*n,0)>st[0])
            ++j;
        ans=max(j-i-1,ans);
    }
    cout<<ans<<endl;
}
 
 
int main(){
    int _;
    cin>>_;
    while(_--)
        solve();
    return 0;
}
