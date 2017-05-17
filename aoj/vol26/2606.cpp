#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline ll lcm(ll x, ll y)
{
    if(x==0) return y;
    if(y==0) return x;
    return x/__gcd(x,y)*y;
}

struct LCMSegTree{
    int n; vector<ll> dat;
    //初期化
    LCMSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=lcm(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return lcm(vl,vr);
    }
    //[a,b)のLCMを求める
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

const int mod=1e9+7;
const int N=100000;

int cycle[N];
int val[N][40];
int pre[N][40]={};

vector<int> sum[41][41];
vector<int> idx[41];

int main()
{
    int n,Q;
    scanf(" %d %d", &n, &Q);

    vector<int> p(n);
    rep(i,n)
    {
        scanf(" %d", &p[i]);
        --p[i];
    }

    rep(i,41)rep(j,41) sum[i][j].pb(0);
    rep(i,41) idx[i].pb(-1);

    LCMSegTree st(n);
    rep(i,n)
    {
        int now = p[i];
        cycle[i] = 1;
        while(1)
        {
            val[i][cycle[i]-1] = now+1;
            if(now == i) break;

            now = p[now];
            ++cycle[i];
        }

        st.update(i,cycle[i]);

        pre[i][0] = val[i][0];
        for(int j=1; j<cycle[i]; ++j) pre[i][j] = pre[i][j-1]+val[i][j];

        sum[cycle[i]][0].pb(0);
        rep(j,cycle[i]) sum[cycle[i]][j+1].pb(pre[i][j]);
        idx[cycle[i]].pb(i);
    }

    rep(i,41)rep(j,41)
    {
        int SZ = sum[i][j].size();
        rep(k,SZ-1) (sum[i][j][k+1] += sum[i][j][k])%=mod;
    }

    while(Q--)
    {
        int l,r;
        scanf(" %d %d", &l, &r);
        --l;
        --r;

        // 周期
        ll c = st.query(l, r+1);
        ll ans = 0;
        for(int i=1; i<=40; ++i)
        {
            int lidx = lower_bound(all(idx[i]),l) - idx[i].begin() - 1;
            int ridx = upper_bound(all(idx[i]),r) - idx[i].begin() - 1;

            ll q=c/i;
            q%=mod;
            (ans+=q*(sum[i][i][ridx]-sum[i][i][lidx]+mod)%mod)%=mod;

            ll rem=c%i;
            (ans+=(sum[i][rem][ridx]-sum[i][rem][lidx]+mod)%mod)%=mod;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
