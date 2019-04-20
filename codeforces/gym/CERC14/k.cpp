#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> P;
typedef pair<P,int> PP;
typedef pair<int,P> IP;

struct datas{
    int v,c;
    datas(){}
    datas(int vv,int cc){
        v=vv;
        c=cc;
    }
    bool operator<(const datas &d)const{
        if((v-c)==(d.v-d.c))return c<d.c;
        return (v-c)<(d.v-d.c);
    }
};

vector<PP> G[150005][11];
int n,k;
datas d[150005];
int dp[150005][11];
int val[150005];

void dijk(){
    priority_queue<IP,vector<IP>,greater<IP> > que;
    que.push(IP(0,P(0,0)));
    dp[0][0]=0;
    while(que.size()){
        IP p=que.top();
        que.pop();
        int v=p.second.first;
        int ck=p.second.second;
        int c=p.first;
        if(dp[v][ck]<c)continue;
        //printf("%d %d %d\n",v,ck,c);
        for(int i=0;i<G[v][ck].size();i++){
            PP np=G[v][ck][i];
            int nv=np.first.first;
            int nk=np.first.second;
            int nc=c+np.second;
            if(dp[nv][nk]>nc){
                dp[nv][nk]=nc;
                que.push(IP(nc,P(nv,nk)));
            }
        }
    }
}

void solve(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=k+1;j++){
            dp[i][j]=114514190;
            G[i][j].clear();
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&d[i].v,&d[i].c);
    }
    sort(d,d+n);
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            G[j][i].push_back(PP(P(j+1,i),0));
            if(i==k){
                G[j][i].push_back(PP(P(n,i+1),-(d[j].v-d[j].c)));
            }
        }
    }
    for(int i=0;i<n;i++){
        val[i]=d[i].v-d[i].c;
    }
    for(int i=0;i<n;i++){
        int pos=lower_bound(val,val+n,d[i].v)-val;
        //printf("%d\n",pos);
        for(int j=0;j<k;j++){
            G[i][j].push_back(PP(P(pos,j+1),d[i].c));
        }
    }
    dijk();
    printf("%d\n",max(0,-dp[n][k+1]));
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        solve();
    }
    return 0;
}

