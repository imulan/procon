#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> P;

struct datass{
    int x1,x2,v;
    int y;
    int type;
    int pos;
    datass(){}
    datass(int xx,int xx2,int vv,int yy,int tt,int pp){
        x1=xx;
        x2=xx2;
        v=vv;
        y=yy;
        type=tt;
        pos=pp;
    }
    
    bool operator <(const datass &d)const{
        if(y==d.y)return type<d.type;
        return y<d.y;
    }
};

struct segtree{
    vector<int> vi;
    int N;
    int* dp;
    
    segtree(){}
    
    void init(){
        N=1;
        while((int)vi.size()>N){
            N*=2;
        }
        dp=new int[N*2];
        for(int i=0;i<N*2;i++){
            dp[i]=0;
        }
    }
    
    void update(int k,int v){
        k+=N-1;
        //printf("%d\n",k);
        dp[k]+=v;
        while(k>0){
            //printf("%d %d\n",k,v);
            k=(k-1)/2;
            dp[k]=dp[k*2+1]+dp[k*2+2];
        }
    }
    
    int query(int a,int b,int k,int l,int r){
        if(r<=a || b<=l)return 0;
        if(a<=l && r<=b)return dp[k];
        int mid=(l+r)/2;
        int vl=query(a,b,k*2+1,l,mid);
        int vr=query(a,b,k*2+2,mid,r);
        return vl+vr;
    }
    
    int query(int a,int b){
        return query(a,b,0,0,N);
    }
};

struct segtree2d{
    int N=1<<18;
    segtree seg[1<<19];
    
    segtree2d(){}
    void add(int k,int y){
        k+=N-1;
        seg[k].vi.push_back(y);
        while(k>0){
            k=(k-1)/2;
            seg[k].vi.push_back(y);
        }
    }
    
    void update(int k,int y){
        k+=N-1;
        int pos=lower_bound(seg[k].vi.begin(),seg[k].vi.end(),y)-seg[k].vi.begin();
        seg[k].update(pos,1);
        while(k>0){
            k=(k-1)/2;
            pos=lower_bound(seg[k].vi.begin(),seg[k].vi.end(),y)-seg[k].vi.begin();
            seg[k].update(pos,1);
        }
    }
    int query(int a,int b,int a2,int b2,int k,int l,int r){
        if(seg[k].vi.size()==0)return 0;
        if(r<=a || b<=l)return 0;
        if(a<=l && r<=b){
            a2=lower_bound(seg[k].vi.begin(),seg[k].vi.end(),a2)-seg[k].vi.begin();
            b2=lower_bound(seg[k].vi.begin(),seg[k].vi.end(),b2)-seg[k].vi.begin();
            return seg[k].query(a2,b2);
        }
        int mid=(l+r)/2;
        int vl=query(a,b,a2,b2,k*2+1,l,mid);
        int vr=query(a,b,a2,b2,k*2+2,mid,r);
        return vl+vr;
    }
    
    int query(int a,int b,int a2,int b2){
        return query(a,b,a2,b2,0,0,N);
    }
};

struct segtree2d2{
    int N=1<<18;
    segtree seg[1<<19];
    
    segtree2d2(){}
    void add(int a,int b,int a2,int k,int l,int r){
        if(r<=a || b<=l)return;
        if(a<=l && r<=b){
            //int pos=lower_bound(seg[k].vi.begin(),seg[k].vi.end(),a2)-seg[k].vi.begin();
            seg[k].vi.push_back(a2);
            return;   
        }
        int mid=(l+r)/2;
        add(a,b,a2,k*2+1,l,mid);
        add(a,b,a2,k*2+2,mid,r);
    }
    
    void update(int a,int b,int a2,int v,int k,int l,int r){
        if(r<=a || b<=l)return;
        if(a<=l && r<=b){
            int pos=lower_bound(seg[k].vi.begin(),seg[k].vi.end(),a2)-seg[k].vi.begin();
            seg[k].update(pos,v);
            return;   
        }
        int mid=(l+r)/2;
        update(a,b,a2,v,k*2+1,l,mid);
        update(a,b,a2,v,k*2+2,mid,r);
        
    }
    
    
    void add(int a,int b,int a2){  
        add(a,b,a2,0,0,N);
    }
    
    void update(int a,int b,int a2,int v){
        update(a,b,a2,v,0,0,N);
    }
    
    int query(int k,int b){
        k+=N-1;
        int ans=0;
        int pos=lower_bound(seg[k].vi.begin(),seg[k].vi.end(),b)-seg[k].vi.begin();
        if(pos!=0){
            ans+=seg[k].query(0,pos);
        }
        while(k>0){
            k=(k-1)/2;
            pos=lower_bound(seg[k].vi.begin(),seg[k].vi.end(),b)-seg[k].vi.begin();
            if(pos!=0){
                ans+=seg[k].query(0,pos);
            }
        }
        return ans;
    }
};

segtree2d segs;
segtree2d2 segs2;
int n;
int t[100005];
P p[100005],p2[100005];
vector<int> xi;
vector<int> yi;
ll ans[100005];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
        scanf("%d%d",&p[i].fi,&p[i].se);
        xi.push_back(p[i].fi);
        yi.push_back(p[i].se);
        if(t[i]==2){
            scanf("%d%d",&p2[i].fi,&p2[i].se);
            xi.push_back(p2[i].fi);
            yi.push_back(p2[i].se);
        }
    }
    sort(xi.begin(),xi.end());
    xi.erase(unique(xi.begin(),xi.end()),xi.end());
    sort(yi.begin(),yi.end());
    yi.erase(unique(yi.begin(),yi.end()),yi.end());
    for(int i=0;i<n;i++){
        p[i].fi=lower_bound(xi.begin(),xi.end(),p[i].fi)-xi.begin();
        p[i].se=lower_bound(yi.begin(),yi.end(),p[i].se)-yi.begin();
        p2[i].fi=lower_bound(xi.begin(),xi.end(),p2[i].fi)-xi.begin();
        p2[i].se=lower_bound(yi.begin(),yi.end(),p2[i].se)-yi.begin();
        if(t[i]==1){
            segs.add(p[i].fi,p[i].se);           
        }
    }
    //printf("a\n");
    for(int i=0;i<segs.N*2;i++){
        sort(segs.seg[i].vi.begin(),segs.seg[i].vi.end());
        segs.seg[i].init();
    }
    //printf("a\n");
    for(int i=0;i<n;i++){
        //printf("%d\n",i);
        if(t[i]==1){
            segs.update(p[i].fi,p[i].se);
        }else{
            ans[i]+=segs.query(p[i].fi,p2[i].fi+1,p[i].se,p2[i].se+1);
        }
    }
    vector<datass> vec;
    for(int i=0;i<n;i++){
        if(t[i]==1){
            vec.push_back(datass(p[i].fi,0,0,p[i].se,2,i));
        }else{
            vec.push_back(datass(p[i].fi,p2[i].fi+1,1,p[i].se,1,i));
            vec.push_back(datass(p[i].fi,p2[i].fi+1,-1,p2[i].se+1,1,i));
            segs2.add(p[i].fi,p2[i].fi+1,i);
        }
    }
    for(int i=0;i<segs.N*2;i++){
        sort(segs2.seg[i].vi.begin(),segs2.seg[i].vi.end());
        segs2.seg[i].init();
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        datass d=vec[i];
        if(d.type==1){
            ans[d.pos]+=segs2.query(d.x1,d.pos);
        }else{
            segs2.update(d.x1,d.x2,d.pos,d.v);
        }
    }
    for(int i=0;i<n;i++){
        printf("%lld\n",ans[i]);
        ans[i+1]+=ans[i];
    }
    return 0;
}
