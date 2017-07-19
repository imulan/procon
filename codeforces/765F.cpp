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

struct MinSegTree{
    int n; vector<ll> dat;
    //初期化
    MinSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,LLONG_MAX);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=min(dat[k],a);
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return LLONG_MAX;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    //[a,b)の最小値
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int m;
    scanf(" %d", &m);
    vector<int> l(m),r(m);
    rep(i,m)
    {
        scanf(" %d %d", &l[i], &r[i]);
        --l[i];
        --r[i];
    }

    vector<int> v(a);
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    int V = v.size();

    vector<ll> ans(m,INT_MAX);
    rep(_,2)
    {
        vector<vector<pair<int,int>>> Q(n);
        rep(i,m) Q[r[i]].pb({l[i],i});

        // 答えを保存
        MinSegTree st(n);
        // 各値が登場した一番右のindexを保存
        MinSegTree idxs(V+1);

        // 区間の右端を右に1つずつずらしながらクエリに答える
        rep(i,n)
        {
            // 最小値を更新
            ll y = 1234567890;
            int idx = lower_bound(all(v),a[i])-v.begin();
            while(y>a[i])
            {
                int L = idx, R = lower_bound(all(v),y)-v.begin();
                ll j = -idxs.query(L,R);
                if(j<0) break;
                st.update(j,a[j]-a[i]);
                y = (a[i]+y)/2;
            }

            idxs.update(idx,-i);

            // クエリに答える
            for(auto &p:Q[i])
            {
                int id = p.se;
                ans[id] = min(ans[id], st.query(p.fi,i+1));
            }
        }

        // 配列とクエリをreverseして同じ処理をする
        reverse(all(a));
        rep(i,m)
        {
            l[i] = n-1-l[i];
            r[i] = n-1-r[i];
            swap(l[i],r[i]);
        }
    }

    rep(i,m) printf("%lld\n", ans[i]);
    return 0;
}
