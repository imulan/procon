#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
typedef pair<int,int> P;

const int N=1<<20;
int qsz=0;
queue<int> que[100005];
int cnt[1<<21];
int id[1<<21];
int a[100005];
int sum[100005];

void init(){
    memset(id,-1,sizeof(id));
}

void add(int v,int idz){
    v+=N-1;
    cnt[v]++;
    if(id[v]==-1){
        id[v]=qsz++;
    }
    //printf("%d\n",id[v]);
    que[id[v]].push(idz);
    while(v>0){
        v=(v-1)/2;
        cnt[v]=cnt[v*2+1]+cnt[v*2+2];
    }
}

void del(int v){
    v+=N-1;
    cnt[v]--;
    que[id[v]].pop();
    while(v>0){
        v=(v-1)/2;
        cnt[v]=cnt[v*2+1]+cnt[v*2+2];
    }
}

P query(int v){
    int cur=0;
    P ans=P(0,-1);
    int k=0;
    for(int i=19;i>=0;i--){
        int b=1-((v>>i)&1);
        int nxt=k*2+1+b;
        if(cnt[nxt]==0){
            nxt=k*2+1+(1-b);
        }else{
            ans.first+=(1<<i);
        }
        k=nxt;
    }
    //printf("%d %d\n",k,N);
    ans.second=que[id[k]].front();
    return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    init();
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum[i+1]+=sum[i];
        sum[i+1]^=a[i];
        add(sum[i+1],i+1);
    }
    int ans=-1;
    P p=P(0,0);
    for(int i=0;i<n;i++){
        P q=query(sum[i]);
        if(q.first>ans){
            ans=q.first;
            p=P(i+1,q.second);
        }
        del(sum[i+1]);
    }
    printf("%d %d %d\n",ans,p.first,p.second);
    return 0;
}