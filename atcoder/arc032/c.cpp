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

struct MaxSegTree{
    long n; vector<ll> dat;
    //初期化
    MaxSegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)の値をaに変更
    void update(long k, ll a){
        k+=n-1;
        dat[k]=max(dat[k],a);
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    //[a,b)の最大値を求める
    ll query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

using pi = pair<int,int>;
using P = pair<pi,int>;

int main()
{
    int n;
    cin >>n;

    vector<P> job(n);
    vector<int> t;

    rep(i,n)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        t.pb(a);
        t.pb(b);
        job[i] = P(pi(b,a),i);
    }
    // ソートする前の状態を保存
    vector<P> def_job(job);

    sort(all(job));
    sort(all(t));
    t.erase(unique(all(t)),t.end());
    int T = t.size();

    MaxSegTree st(T);
    vector<int> dp(n);
    for(int i=n-1; i>=0; --i)
    {
        int id = job[i].se;
        int a = job[i].fi.se, b = job[i].fi.fi;

        int aidx = lower_bound(all(t),a) - t.begin();
        int bidx = lower_bound(all(t),b) - t.begin();
        dp[id] = st.query(bidx,T)+1;
        st.update(aidx,dp[id]);
    }

    int X = *max_element(all(dp));
    vector<int> x;

    vector<vector<int>> J(X+1);
    rep(i,n) J[dp[i]].pb(i);

    int now = 0;
    for(int i=X; i>0; --i)
    {
        int nx = 19191919;
        int n_now = 19191919;
        for(int id:J[i])
        {
            int a = def_job[id].fi.se, b = def_job[id].fi.fi;
            if(now<=a && id<nx)
            {
                nx = id;
                n_now = b;
            }
        }
        x.pb(nx+1);
        now = n_now;
    }

    printf("%d\n", X);
    rep(i,X) printf("%d%c", x[i],(i==X-1?'\n':' '));
    return 0;
}
