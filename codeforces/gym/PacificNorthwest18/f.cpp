#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct query{
    int l,r,y;
    query(){}
    query(int l1,int r1,int y1){
        l=l1;
        r=r1;
        y=y1;
    }
    bool operator<(const query &d)const{
        return y<d.y;
    }
};

struct segtree{
    static const int N=1<<18;
    int dp[1<<19];
    int siz[1<<19];
    bool lazy[1<<19];
    segtree(){ 
        memset(lazy,false,sizeof(lazy));
    }
    
    void add(int k,int v){
        k+=N-1;
        siz[k]+=v;
        while(k>0){
            k=(k-1)/2;
            siz[k]=siz[k*2+1]+siz[k*2+2];
        }
    }
    
    void lazy_eval(int k){
        if(!lazy[k])return;
        dp[k]=siz[k]-dp[k];
        if(k<N-1){
            lazy[k*2+1]=!lazy[k*2+1];
            lazy[k*2+2]=!lazy[k*2+2];
        }
        lazy[k]=false;
    }
    
    void lazy_upd(int k){
        dp[k]=dp[k*2+1]+dp[k*2+2];
    }
    
    void update(int a,int b,int k=0,int l=0,int r=N){
        lazy_eval(k);
        if(b<=l || r<=a)return;
        if(a<=l && r<=b){
            lazy[k]=!lazy[k];
            lazy_eval(k);
            return;
        }
        int mid=(l+r)/2;
        update(a,b,k*2+1,l,mid);
        update(a,b,k*2+2,mid,r);
        lazy_upd(k);
    }
    
    int query(int a,int b,int k=0,int l=0,int r=N){
        lazy_eval(k);
        if(b<=l || r<=a)return 0;
        if(a<=l && r<=b)return dp[k];
        int mid=(l+r)/2;
        int vl=query(a,b,k*2+1,l,mid);
        int vr=query(a,b,k*2+2,mid,r);
        lazy_upd(k);
        return vl+vr;
    }
};

vector<int> xi;
vector<query> vec;
int n;
int x[100005][2];
int y[100005][2];
segtree seg;


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
        if(x[i][0]>x[i][1])swap(x[i][0],x[i][1]);
        if(y[i][0]>y[i][1])swap(y[i][0],y[i][1]);
        xi.push_back(x[i][0]);
        xi.push_back(x[i][1]);
    }
    sort(xi.begin(),xi.end());
    xi.erase(unique(xi.begin(),xi.end()),xi.end());
    for(int i=0;i<n;i++){
        x[i][0]=lower_bound(xi.begin(),xi.end(),x[i][0])-xi.begin();
        x[i][1]=lower_bound(xi.begin(),xi.end(),x[i][1])-xi.begin();
        vec.push_back(query(x[i][0],x[i][1],y[i][0]));
        vec.push_back(query(x[i][0],x[i][1],y[i][1]));
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i+1<xi.size();i++){
        seg.add(i,xi[i+1]-xi[i]);
    }
    ll prev=0,ans=0;
    for(int i=0;i<vec.size();i++){
        query q=vec[i];
        ans+=(ll)(q.y-prev)*seg.query(0,seg.N);
        seg.update(q.l,q.r);
        prev=q.y;
      //  printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}

