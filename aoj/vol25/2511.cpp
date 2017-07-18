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

using pi = pair<int,int>;
using P = pair<int,pi>;

const int INF = 200000002;

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

int b[200][200];

int solve(int n, int m)
{
    memset(b,-1,sizeof(b));

    vector<int> h(n);
    rep(i,n) scanf(" %d", &h[i]);

    vector<P> e(m);
    rep(i,m)
    {
        int u,v,c;
        scanf(" %d %d %d", &u, &v, &c);
        --u;
        --v;
        b[u][v] = b[v][u] = c;
        e[i] = P(c,pi(u,v));
    }

    sort(all(e));

    UF uf(n);
    rep(i,m) uf.unite(e[i].se.fi, e[i].se.se);
    if(uf.size(0) < n) return 0;

    vector<int> sh(h);
    sh.pb(0);
    sort(all(sh));
    sh.erase(unique(all(sh)),sh.end());
    int SH = sh.size();

    int idx = 0;
    // どの島まで沈むと非連結になるかを探す
    while(idx<SH)
    {
        // printf("IDX %d  sh = %d\n", idx,sh[idx]);
        uf = UF(n);
        rep(i,m)
        {
            int u = e[i].se.fi, v = e[i].se.se;
            if(h[u]>sh[idx] && h[v]>sh[idx])
            {
                uf.unite(u,v);
            }
        }

        int num = 0;
        int cand = 0;
        rep(i,n)
        {
            if(h[i]>sh[idx])
            {
                ++num;
                cand = i;
            }
        }
        // dbg(idx);
        // dbg(num);

        if(uf.size(cand) < num) break;
        ++idx;
    }
    --idx;
    if(idx==SH-1) --idx;

    int ret = 0;
    // dbg(sh[idx]);

    uf = UF(n);
    // 沈まないところは普通にMSTを構成
    rep(i,m)
    {
        int u = e[i].se.fi, v = e[i].se.se;
        if(h[u]>sh[idx] && h[v]>sh[idx])
        {
            if(!uf.same(u,v))
            {
                // printf("  MAKE %d %d\n", u,v);
                uf.unite(u,v);
                ret += e[i].fi;
            }
        }
    }

    // 沈むところはそれ以降に沈むところと繋ぐが、同じ日に沈むのに注意
    vector<int> sink[201];
    rep(i,n)
    {
        int sh_idx = lower_bound(all(sh),h[i])-sh.begin();
        sink[sh_idx].pb(i);
    }

    vector<int> con;
    for(int i=SH-1; i>0; --i)
    {
        if(i<=idx)
        {
            vector<bool> ap(n);
            rep(j,sink[i].size()) ap[sink[i][j]]=true;

            vector<P> ee;
            rep(j,m)
            {
                int u = e[j].se.fi, v = e[j].se.se;
                if((ap[u]&&h[v]>=h[u]) || (ap[v]&&h[u]>=h[v])) ee.pb(e[j]);
            }

            int add = INF;
            rep(j,sink[i].size())
            {
                int t = INF;
                int V = -1;
                for(const auto &x:con)
                {
                    if(b[sink[i][j]][x]!=-1)
                    {
                        t = min(t,b[sink[i][j]][x]);
                        V = x;
                    }
                }

                if(V==-1) continue;

                UF tuf = uf;
                tuf.unite(sink[i][j],V);
                rep(k,ee.size())
                {
                    int u = ee[k].se.fi, v = ee[k].se.se;
                    if(!tuf.same(u,v))
                    {
                        tuf.unite(u,v);
                        t += ee[k].fi;
                    }
                }

                add = min(add, t);
            }
            ret += add;
        }

        for(const auto &x:sink[i])
        {
            con.pb(x);
            uf.unite(sink[SH-1][0],x);
        }
    }

    return ret;
}

int main()
{
    int n,m;
    while(scanf(" %d %d", &n, &m),n) printf("%d\n", solve(n,m));
    return 0;
}
