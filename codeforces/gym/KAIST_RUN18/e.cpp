#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using P = pair<ll,ll>;
using PP =pair<P,int>;

bool comp(const PP &a, const PP &b){
    ll aa = a.fi.fi+a.fi.se, bb = b.fi.fi+b.fi.se;
    if(aa == bb){
        return a.fi.fi < b.fi.fi;
    }
    return aa < bb;
}

struct segtree{
    static const int N=1<<18;
    ll dp[1<<19];
    int cnt[1<<19];
    segtree(){
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
    }
    
    void update(int k,ll v){
        k+=N-1;
        dp[k]+=v;
        cnt[k]+=1;
        while(k>0){
            k=(k-1)/2;
            dp[k]=dp[k*2+1]+dp[k*2+2];
            cnt[k]=cnt[k*2+1]+cnt[k*2+2];
        }
    }
    
    int query(int a,int b,int k=0,int l=0,int r=N){
        if(r<=a || b<=l)return 0;
        if(a<=l && r<=b)return cnt[k];
        int mid=(l+r)/2;
        int vl=query(a,b,k*2+1,l,mid);
        int vr=query(a,b,k*2+2,mid,r);
        return vl+vr;
    }
    
    int find(ll v){
        int k=0,l=0,r=N;
        int ans=0;
        while(l+1<r){
            int mid=(l+r)/2;
            if(dp[k*2+1]<=v){
                v-=dp[k*2+1];
                ans+=cnt[k*2+1];
                k=k*2+2;
                l=mid;
            }else{
                k=k*2+1;
                r=mid;
            }
        }
        return ans;
    }
};

segtree seg;
vector<PP> vec;
int pos[300005];

int main(){
    int n;
    cin >>n;
    
    vector<PP> v(n);
    rep(i,n){
        ll l,d;
        cin >>l >>d;
        v[i] = PP(P(l,d),i);
        vec.push_back(PP(P(d,l),i));
    }
    sort(all(v), comp);
    //rep(i,n) printf(" %d: %lld %lld\n",i,v[i].fi,v[i].se);
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++){
        pos[vec[i].second]=i;
    }
    int ans = 0;
    rep(i,n){
        int val=seg.find(v[i].fi.fi);
        ans=max(ans,val+1);
        int po=pos[v[i].se];
        printf("%d %d %d\n",val,po,seg.query(0,po));
        if(seg.query(0,po)<=val){
            seg.update(po,v[i].fi.se);
        }
    }
    cout << ans << endl;
    return 0;
}
