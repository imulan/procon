#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

typedef vector<ll> vl;
typedef vector<vl> mat;

mat mul(const mat &a, const mat &b)
{
    mat c(2,vl(2));
    rep(i,2)rep(j,2)
    {
        rep(k,2) (c[i][j]+=a[i][k]*b[k][j])%=mod;
    }
    return c;
}

vl mulv(const mat &a, const vl &b)
{
    vl ret(2);
    ret[0]=(a[0][0]*b[0]+a[0][1]*b[1])%mod;
    ret[1]=(a[1][0]*b[0]+a[1][1]*b[1])%mod;
    return ret;
}

struct MatSegTree{
    int n; vector<mat> dat;
    //初期化
    MatSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<mat>(2*n-1,mat({{0,0},{0,1}}));
    }
    //k番目(0-indexed)のx番の要素に+a
    void add(int k, int x, ll a){
        k+=n-1;

        int p,q;
        if(x==0){p=1;q=0;}
        else if(x==1){p=1;q=1;}
        else{p=0;q=1;}

        (dat[k][p][q]+=a)%=mod;

        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=mul(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    mat _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return mat({{0,0},{0,1}});

        if(a<=l && r<=b) return dat[k];

        mat VL=_query(a,b,2*k+1,l,(l+r)/2);
        mat VR=_query(a,b,2*k+2,(l+r)/2,r);
        return mul(VL,VR);
    }
    //[a,b)の行列積を計算
    mat query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

ll solve()
{
    int N,M;
    cin >>N >>M;

    vector<ll> w(M+1),d(M+1),z(M+1),s(M+1);
    ll A,B;

    cin >>w[1] >>A >>B;
    for(int i=2; i<=M; ++i) w[i]=((A*w[i-1]+B)%N)+1;

    cin >>d[1] >>A >>B;
    for(int i=2; i<=M; ++i) d[i]=(A*d[i-1]+B)%3;

    for(int i=1; i<=M; ++i) z[i]=max(1LL, min((ll)N,w[i]+d[i]-1));

    cin >>s[1] >>A >>B;
    for(int i=2; i<=M; ++i) s[i]=((A*s[i-1]+B)%1000000000)+1;

    MatSegTree st(N);
    ll ret=0;
    for(int i=1; i<=M; ++i)
    {
        // update
        int idx = N-w[i];

        int k;
        if(z[i]<w[i]) k=0;
        else if(z[i]==w[i]) k=1;
        else k=2;

        st.add(idx,k,s[i]);

        // calc
        mat m = st.query(0,N);

        vl res = mulv(m,vl({0,1}));
        (ret+=res[1])%=mod;
    }
    return ret;
}

int main()
{
    int T;
    cin >>T;
    rep(i,T) printf("Case #%d: %lld\n", i+1, solve());
    return 0;
}
