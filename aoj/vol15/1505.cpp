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

struct SegTree{
    int n; vector<int> dat;
    //初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<int>(2*n-1,0);
    }

    void add(int k, int a){
        k+=n-1;
        dat[k] += a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]+dat[2*k+2];
        }
    }
    //内部的に投げられるクエリ
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        int vl=_query(a,b,2*k+1,l,(l+r)/2);
        int vr=_query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
    //[a,b)
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

const int N = 100000;
const ll INF = LLONG_MAX/3;

struct edge{ int to,cost; };
vector<edge> G[N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m){
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        G[a].pb({b,c});
        G[b].pb({a,c});
    }

    auto dijkstra = [&](int start){
        using P = pair<ll,int>;
        vector<ll> d(n,INF);
        priority_queue<P, vector<P>, greater<P>>pq;
        d[start] = 0;
        pq.push({0,start});
        while(!pq.empty()){
            P now = pq.top();
            pq.pop();
            int v = now.se;
            if(now.fi > d[v]) continue;
            for(const auto &e:G[v]){
                if(d[e.to] > d[v]+e.cost){
                    d[e.to] = d[v]+e.cost;
                    pq.push({d[e.to], e.to});
                }
            }
        }
        return d;
    };

    vector<ll> s = dijkstra(0), g = dijkstra(n-1);

    using pl = pair<ll,ll>;
    using query = pair<pl,int>;

    vector<ll> ug;

    int Q;
    scanf(" %d", &Q);
    vector<query> q(Q);
    rep(i,Q){
        ll fs,fg;
        scanf(" %lld %lld", &fs, &fg);
        q[i] = {{fs,fg}, i};
        ug.pb(fg);
    }
    sort(all(q));

    vector<pl> v(n);
    rep(i,n){
        v[i] = {s[i],g[i]};
        ug.pb(g[i]);
    }
    sort(all(v));

    sort(all(ug));
    ug.erase(unique(all(ug)), ug.end());
    int UG = ug.size();

    SegTree st(UG);

    int idx = 0;
    vector<int> ans(Q);
    rep(i,Q){
        int ID = q[i].se;
        ll fs = q[i].fi.fi, fg = q[i].fi.se;

        while(idx<n && v[idx].fi<=fs){
            int a_idx = lower_bound(all(ug), v[idx].se)-ug.begin();
            st.add(a_idx, 1);
            ++idx;
        }

        int gidx = lower_bound(all(ug), fg)-ug.begin();
        ans[ID] = st.query(gidx, UG);
    }

    rep(i,Q) printf("%d\n", ans[i]);
    return 0;
}
