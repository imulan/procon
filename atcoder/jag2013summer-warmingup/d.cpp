#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()

struct uftree{
    int par[200005];
    int rank[200005];

    void init(int n){
        for(int i=0;i<=n;i++){
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x){
        if(par[x]==x)return par[x];
        return par[x]=find(par[x]);
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return;
        if(rank[x]<rank[y]){
            par[x]=y;
        }else{
            if(rank[x]==rank[y])rank[x]++;
            par[y]=x;
        }
    }

    bool same(int x,int y){
        return find(x)==find(y);
    }
};

uftree uf;
int n,m,k;
int u[100005],v[100005];
bool used[100005];
int t[100005];
int a[100005],b[100005];
bool ans[100005];

void solve(){
    uf.init(n);
    for(int i=0;i<k;i++){
        if(t[i]==0){
            used[a[i]]=true;
        }
    }
    for(int i=0;i<m;i++){
        if(!used[i]){
            uf.unite(u[i],v[i]);
        }
    }
    for(int i=k-1;i>=0;i--){
        if(t[i]==1){
            ans[i]=uf.same(a[i],b[i]);
        }else{
            uf.unite(u[a[i]],v[a[i]]);
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d%d",&u[i],&v[i]);
        u[i]--;
        v[i]--;
    }
    for(int i=0;i<k;i++){
        scanf("%d%d",&t[i],&a[i]);
        a[i]--;
        if(t[i]==1){
            scanf("%d",&b[i]);
            b[i]--;
        }
    }
    solve();
    for(int i=0;i<k;i++){
        if(t[i]==1){
            printf("%s\n",ans[i]?"YES":"NO");
        }
    }
    return 0;
}