#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)n;++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct NODE{
    int l,r;
    int ele=0;
    int cnt[32];
};

int siz;
NODE node[3500000];
ll x;
int n,q;

void update_cnt(int cur,ll val){
    node[cur].ele++;
    for(int i=0;i<32;i++){
        if(val>>i & 1LL){
            node[cur].cnt[i]++;
        }
    }
}

void add(ll a){
    int cur=0;
    for(int i=31;i>=0;i--){
        //printf("%d %d %lld\n",cur,i,a);
        update_cnt(cur,a);
        if(a>>i & 1LL){
            if(node[cur].r==-1){
                node[cur].r=siz++;
            }
            cur=node[cur].r;
        }else{
            if(node[cur].l==-1){
                node[cur].l=siz++;
            }
            cur=node[cur].l;
        }
    }
    update_cnt(cur,a);
}

ll get_val(int cur,int rest){
    ll res=0;
    for(int i=0;i<32;i++){
        //printf("%d ",node[cur].cnt[i]);
        ll co=node[cur].cnt[i];
        if(x>>i & 1){
            co=node[cur].ele-node[cur].cnt[i];
        }
        co=min(co,(ll)rest);
        res+=(ll)co*(1LL<<i);
    }
    //printf("\n");
    //printf("getval %d %d %lld\n",cur,rest,res);
    return res;
}

ll dfs(int cur,int bitpos,int rest){
    if(cur==-1 || rest<=0)return 0;
    //printf("%d %d %d %d %lld\n",cur,node[cur].ele,bitpos,rest,x);
    if(bitpos==-1){
        return get_val(cur,rest);
    }
    if(node[cur].r==-1)return dfs(node[cur].l,bitpos-1,rest);
    if(node[cur].l==-1)return dfs(node[cur].r,bitpos-1,rest);
    int lv=node[cur].l;
    int rv=node[cur].r;
    if(x>>bitpos & 1LL){
        if(node[rv].ele<=rest){
            ll res=get_val(rv,rest);
            return res+dfs(lv,bitpos-1,rest-node[rv].ele);
        }else{
            return dfs(rv,bitpos-1,rest);
        }
    }else{
        if(node[lv].ele<=rest){
            ll res=get_val(lv,rest);
            return res+dfs(rv,bitpos-1,rest-node[lv].ele);
        }else{
            return dfs(lv,bitpos-1,rest);
        }
    }
}


void solve(){
    for(int i=0;i<siz;i++){
        node[i].l=-1;
        node[i].r=-1;
        node[i].ele=0;
        memset(node[i].cnt,0,sizeof(node[i].cnt));
    }
    siz=1;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        ll a;
        scanf("%lld",&a);
        add(a);
    }
    x=0;
    for(int i=0;i<q;i++){
        int t;
        ll v;
        scanf("%d%lld",&t,&v);
        if(t==1){
            x^=v;
        }else{
            printf("%lld\n",dfs(0,31,v));
        }
    }
}

int main(){
    int T;
    siz=3500000;
    cin >>T;
    while(T--)solve();
    return 0;
}
