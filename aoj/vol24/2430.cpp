#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const ll INF = LLONG_MAX/3;
using P = pair<ll,int>;

const int N = 4004;

struct SegTree{
    int n; vector<P> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<P>(2*n-1,{INF,N});
    }
    //k番目(0-indexed)の値をaに更新
    void update_min(int k, ll a, int idx){
        // printf("  UPD: %d %lld\n",k,a);
        k+=n-1;
        dat[k] = min(dat[k], {a,idx});
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    P _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return {INF,N};
        if(a<=l && r<=b) return dat[k];

        P vl=_query(a,b,2*k+1,l,(l+r)/2);
        P vr=_query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    //[a,b)
    P query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

ll dp[N][N];
int par[N][N];

int main(){
    int n;
    scanf(" %d", &n);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    vector<ll> s(n+1);
    for(int i=1; i<=n; ++i) s[i] = s[i-1]+a[i-1];

    fill(dp[0],dp[N],INF);
    dp[0][0] = -INF;

    fill(par[0],par[N],-1);

    for(int i=1; i<=n; ++i){

        vector<ll> v;
        rep(j,n+1){
            v.pb(s[j] + dp[i-1][j]);
        }
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        // dbg(v);

        int V = v.size();
        SegTree st(V);

        rep(j,n+1){
            int idx = lower_bound(all(v), s[j]) - v.begin();
            P res = st.query(0,idx);
            // dbg(res);
            if(res.fi < INF && dp[i][j] > s[j] + res.fi){
                dp[i][j] = s[j] + res.fi;
                par[i][j] = res.se;
            }

            int uidx = lower_bound(all(v), s[j]+dp[i-1][j]) - v.begin();
            st.update_min(uidx, -s[j], j);

            // printf(" %d: idx %d  uidx %d\n",j,idx,uidx);
        }

        // printf(" --------- i %d\n",i);
        // rep(j,n+1) printf(" dp %d  %lld  , par %d\n",j,dp[i][j],par[i][j]);
    }

    int m = 0;
    rep(i,n+1){
        if(dp[i][n] < INF) m = i;
    }

    int now = n;
    vector<int> ans;
    rep(i,m-1){
        now = par[m-i][now];
        ans.pb(now);
        // printf("%d\n", now);
    }

    reverse(all(ans));

    printf("%d\n", m);
    rep(i,m-1) printf("%d%c", ans[i], " \n"[i==m-2]);
    return 0;
}
