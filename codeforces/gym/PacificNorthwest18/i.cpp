#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;

struct CHTrick{
    deque<P> lines;
    bool isMonoticX=true;
    CHTrick(bool flag=true){
        isMonoticX=flag;
    }
    
    bool check(P l1,P l2,P l3){
        return (long double)(l3.second-l2.second)*(l2.first-l1.first)>=(long double)(l2.second-l1.second)*(l3.first-l2.first);
    }
    
    void add(ll a,ll b){
        if(lines.size()>0 && lines.back().first==a){
            b=max(b,lines.back().second);
            lines.pop_back();
        }
        P line(a,b);
        while(lines.size()>=2 && check(*(lines.end()-2),lines.back(),line)){
            lines.pop_back();
        }
        lines.push_back(line);
    }
    
    ll f(int i,ll x){
        return lines[i].first*x+lines[i].second;
    }
    
    ll f(P line, ll x){
        return line.first*x+line.second;
    }
    bool comp(ll lv,ll rv){
        return lv<=rv;
    }
    
    ll get(ll x){
        if(isMonoticX){
            while(lines.size()>=2 && comp(f(0,x),f(1,x))){
                lines.pop_front();
            }
            return f(0,x);
        }else{
            int low=-1,high=lines.size()-1;
            while(high-low>1){
                int mid=(high+low)/2;
                if(comp(f(mid,x),f(mid+1,x)))low=mid;
                else high=mid;
            }
            return f(high,x);
        }
    }
};

struct segtree{
    int N=1<<8;
    int dp[1<<9];
    
    segtree(){}
    
    void add(int k,int v){
        k+=N-1;
        dp[k]+=v;
        while(k>0){
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

int n,K;
int a[200005];
int cnt[102];
ll sum[200001][102];
CHTrick ch[102];
segtree seg;


ll solve(){
    int zero=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            ll s=0;
            for(int j=K;j>=0;j--){
                sum[zero+1][j]+=s;
                s+=cnt[j];
            }
            zero++;
        }else{
            cnt[a[i]]++;
        }
    }
    memset(cnt,0,sizeof(cnt));
    int z2=zero;
    for(int i=n-1;i>=0;i--){
        if(a[i]==0){
            ll s=0;
            for(int j=0;j<=K;j++){
                sum[z2][j]+=s;
                s+=cnt[j];
            }
            z2--;
        }else{
            cnt[a[i]]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=K;j++){
            sum[i+1][j]+=sum[i][j];
        }
    }
    for(int i=0;i<=K+1;i++){
        ch[i].add(0,0);
    }
    ll ans=0LL;
    for(int i=1;i<=zero;i++){
        for(int j=K;j>=1;j--){
            ll val=ch[j+1].get(i)+sum[i][j];
            ans=max(ans,val);
            //printf("%d %d %lld\n",i,j,val);
            ch[j].add(i,val-sum[i][j-1]-i*i);
        }
    }
    return ans;
}

ll solve2(){
    ll res=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)continue;
        res+=seg.query(a[i]+1,seg.N);
        seg.add(a[i],1);
    }
    return res;    
}

int main(){
    scanf("%d%d",&n,&K);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%lld\n",solve()+solve2());
    
    
    return 0;
}

